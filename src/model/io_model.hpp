#pragma once
#include <QAbstractTableModel>
#include <QStringList>
#include <QTimer>
#include <iterator>
#include <mutex>
#include <vector>

#include "../util/config_manager.hpp"
#include "../util/shm_manager.hpp"

class IOModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit IOModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {
        headers_ << "IO编号" << "名称" << "类型" << "状态";

        auto *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this,
                [this]() { emit dataChanged(index(0, columnCount() - 1), index(rowCount() - 1, columnCount() - 1)); });
        connect(&ShmManager::get_instance(), &ShmManager::loaded, [timer, this](bool success) {
            if (success) {
                beginResetModel();
                auto &io_config = ConfigManager::get_instance().get_config().io_config;
                io_count_ = static_cast<int>(OUT_MAX) + static_cast<int>(VALVE_MAX);
                endResetModel();
                timer->start(500);
            } else {
                timer->stop();
            }
        });
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return io_count_;
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return static_cast<int>(headers_.size());
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (io_count_ == 0) {
            return {};
        }

        if (!index.isValid()) {
            return {};
        }

        if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
        }

        int row = index.row();
        if (role == Qt::DisplayRole) {
            if (row < 0 || row >= io_count_) {
                return {};
            }

            switch (index.column()) {
                case 0:
                    return row;
                case 1: {
                    if (row < IN_MAX) {
                        return input2name[static_cast<INPUT_SIGNAL_NAME>(row)];
                    } else if (row < OUT_MAX) {
                        return output2name[static_cast<OUTPUT_SIGNAL_NAME>(row)];
                    } else {
                        return valve2name[static_cast<VALVE_OUTPUT_NAME>(row - OUT_MAX)];
                    }
                }
                case 2:
                    if (row < IN_MAX) {
                        return "输入";
                    } else if (row < OUT_MAX) {
                        return "输出";
                    } else {
                        return "阀岛";
                    }
                case 3: {
                    IO io_{};
                    {
                        std::lock_guard<std::mutex> guard_{lock_};
                        io_ = ShmManager::get_instance().get_data()->io;
                    }
                    int isOn;

                    int *l2p = row < OUT_MAX
                                   ? ConfigManager::get_instance().get_config().io_config.digital_logic_to_physical
                                   : ConfigManager::get_instance().get_config().io_config.valve_logic_to_physical;

                    if (row < IN_MAX) {
                        isOn = (io_.digital_input[l2p[row] / 8] >> (l2p[row] % 8)) & 1;
                    } else if (row < OUT_MAX) {
                        isOn = (io_.digital_output[(l2p[row] / 8) - std::size(io_.digital_input)] >> (l2p[row] % 8)) & 1;
                    } else {
                        row -= OUT_MAX;
                        isOn = (io_.valve_output[l2p[row] / 8] >> (l2p[row] % 8)) & 1;
                    }

                    return isOn;
                }
                default:
                    return {};
            }
        }

        return {};
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
        }

        if (role == Qt::DisplayRole) {
            if (orientation == Qt::Horizontal) {
                return headers_.at(section);
            } else {
                return section + 1;
            }
        }

        return {};
    }

private:
    QStringList headers_;
    int io_count_{0};

    mutable std::mutex lock_;
};
