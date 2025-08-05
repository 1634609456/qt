#pragma once

#include <QAbstractTableModel>
#include <QStringList>

#include "../util/shm_manager.hpp"

class MotorConfigModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit MotorConfigModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {
        headers_ << "电机编号" << "站序号" << "名称" << "运行速度" << "最大速度" << "最小速度"
                 << "加速度" << "急停减速度" << "缓停减速度"
                 << "位置" << "负限位" << "零点位置" << "正限位"
                 << "传动比" << "跟随比" << "扭矩限制" << "编码器脉冲" << "位移当量";
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
            if (index.row() < 0 || index.row() >= dataStorage_.size()) {
                return {};
            }

            const auto &row = dataStorage_.at(index.row());

#define RETURN_COLUMN(index, value) \
    case index:                     \
        return value;

            switch (index.column()) {
                RETURN_COLUMN(0, row.physical_id)
                RETURN_COLUMN(1, row.ECAT_id)
                RETURN_COLUMN(2, motortype2name[static_cast<MOTOR_TYPE>(index.row())])
                RETURN_COLUMN(3, row.running_speed)
                RETURN_COLUMN(4, row.max_speed)
                RETURN_COLUMN(5, row.min_speed)
                RETURN_COLUMN(6, row.acceleration)
                RETURN_COLUMN(7, row.emg_deceleration)
                RETURN_COLUMN(8, row.smooth_deceleration)
                RETURN_COLUMN(9, row.position)
                RETURN_COLUMN(10, row.negative_limit)
                RETURN_COLUMN(11, row.zero_position)
                RETURN_COLUMN(12, row.positive_limit)
                RETURN_COLUMN(13, row.ratio)
                RETURN_COLUMN(14, row.follow_ratio)
                RETURN_COLUMN(15, row.torque_limit)
                RETURN_COLUMN(16, row.encoder_resolution_counter)
                RETURN_COLUMN(17, row.displacement_equivalent)
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

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        if (!index.isValid()) {
            return Qt::NoItemFlags;
        }
        
        // 电机编号(0)、站序号(1)、名称(2) 不可编辑，其他列可编辑
        if (index.column() == 0 || index.column() == 1 || index.column() == 2) {
            return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
        }
        
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override {
        if (!index.isValid() || role != Qt::EditRole) {
            return false;
        }

        if (index.row() < 0 || index.row() >= dataStorage_.size()) {
            return false;
        }

        // 电机编号(0)、站序号(1)、名称(2) 不可编辑
        if (index.column() == 0 || index.column() == 1 || index.column() == 2) {
            return false;
        }

        auto &row = dataStorage_[index.row()];
        bool ok = false;

        switch (index.column()) {
            case 3: // 运行速度
                row.running_speed = value.toDouble(&ok);
                break;
            case 4: // 最大速度
                row.max_speed = value.toDouble(&ok);
                break;
            case 5: // 最小速度
                row.min_speed = value.toDouble(&ok);
                break;
            case 6: // 加速度
                row.acceleration = value.toDouble(&ok);
                break;
            case 7: // 急停减速度
                row.emg_deceleration = value.toDouble(&ok);
                break;
            case 8: // 缓停减速度
                row.smooth_deceleration = value.toDouble(&ok);
                break;
            case 9: // 位置
                row.position = value.toDouble(&ok);
                break;
            case 10: // 负限位
                row.negative_limit = value.toDouble(&ok);
                break;
            case 11: // 零点位置
                row.zero_position = value.toInt(&ok);
                break;
            case 12: // 正限位
                row.positive_limit = value.toDouble(&ok);
                break;
            case 13: // 传动比
                row.ratio = value.toDouble(&ok);
                break;
            case 14: // 跟随比
                row.follow_ratio = value.toDouble(&ok);
                break;
            case 15: // 扭矩限制
                row.torque_limit = value.toDouble(&ok);
                break;
            case 16: // 编码器脉冲
                row.encoder_resolution_counter = value.toDouble(&ok);
                break;
            case 17: // 位移当量
                row.displacement_equivalent = value.toDouble(&ok);
                break;
            default:
                return false;
        }

        if (ok) {
            emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
            return true;
        }

        return false;
    }

    void setDataStorage(const std::vector<MOTOR_DATA> &data) {
        beginResetModel();
        dataStorage_ = data;
        endResetModel();
    }

    const std::vector<MOTOR_DATA>& getDataStorage() const {
        return dataStorage_;
    }

private:
    QStringList headers_;
    std::vector<MOTOR_DATA> dataStorage_;
};
