#pragma once

#include <QAbstractTableModel>
#include <QStringList>
#include <QTimer>
#include <mutex>
#include <vector>

#include "../util/shm_manager.hpp"

class MotorFebModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit MotorFebModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {
        headers_ << "电机名称" << "使能状态" << "回原状态" << "运行状态" << "指令状态" << "运行速度"
                 << "加速度" << "位置"
                 << "跟随比" << "编码器脉冲";

        auto *refresh = new QTimer(this);
        connect(refresh, &QTimer::timeout, this, [this]() {
            decltype(dataStorage_) dataStorage;
            {
                std::lock_guard<std::mutex> guard{lock_};
                auto &array = ShmManager::get_instance().get_data()->feedback.motor_fdb;
                dataStorage = std::vector<MOTOR_FDB_DATA>(std::begin(array), std::end(array));
            }
            if (!dataStorage.empty()) {
                setDataStorage(dataStorage);
                emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
            }
        });
        connect(&ShmManager::get_instance(), &ShmManager::loaded, [refresh](bool success) {
            if (success) {
                refresh->start(500);
            } else {
                refresh->stop();
            }
        });
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return static_cast<int>(dataStorage_.size());
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return static_cast<int>(headers_.size());
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (dataStorage_.empty()) {
            return {};
        }

        if (!index.isValid()) {
            return {};
        }

        if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
        }

        if (role == Qt::DisplayRole) {
            if (index.row() < 0 || index.row() >= static_cast<int>(dataStorage_.size())) {
                return {};
            }

            std::lock_guard<std::mutex> guard{lock_};

            const auto &row = dataStorage_.at(index.row());

#define RETURN_COLUMN(index, value) \
    case index:                     \
        return value;

            switch (index.column()) {
                RETURN_COLUMN(0, motortype2name[static_cast<MOTOR_TYPE>(index.row())])
                RETURN_COLUMN(1, row.motor_power_state)
                RETURN_COLUMN(2, row.motor_is_homed)
                RETURN_COLUMN(3, row.motor_is_active)
                RETURN_COLUMN(4, row.motor_is_done)
                RETURN_COLUMN(5, row.running_speed)
                RETURN_COLUMN(6, row.acceleration)
                RETURN_COLUMN(7, row.position)
                RETURN_COLUMN(8, row.follow_ratio)
                RETURN_COLUMN(9, row.encoder_resolution_counter)
                default:
                    return {};
            }

#undef RETURN_COLUMN
        }

        return {};
    }

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override {
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

    void setDataStorage(const std::vector<MOTOR_FDB_DATA> &data) {
        beginResetModel();
        dataStorage_ = data;
        endResetModel();
    }

private:
    QStringList headers_;
    std::vector<MOTOR_FDB_DATA> dataStorage_;

    mutable std::mutex lock_;
};
