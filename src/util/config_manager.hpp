#pragma once

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <stdexcept>

#include "../shm_data.hpp"

class ConfigManager {
public:
    inline static QString ERR_STR;
    
    bool load() {
        QFile file("./config.json");
        if (!file.open(QIODevice::ReadOnly)) {
            ERR_STR = QString("无法打开配置文件: %1").arg(file.errorString());
            return false;
        }

        QByteArray data = file.readAll();
        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
        if (parseError.error != QJsonParseError::NoError || !doc.isObject()) {
            ERR_STR = QString("JSON解析错误: %1").arg(parseError.errorString());
            return false;
        }

        try {
            _from_json(doc.object());
        } catch (const std::runtime_error &e) {
            ERR_STR = QString("配置解析错误: %1").arg(e.what());
            return false;
        }

        return true;
    }

    static ConfigManager &get_instance() {
        static ConfigManager instance;
        return instance;
    }

    CONFIG &get_config() {
        return config_;
    }

private:
    CONFIG config_{};
    void _from_json(const QJsonObject &json) {
        // Parse motors
        if (!json.contains("motor") || !json["motor"].isArray()) {
            throw std::runtime_error("Missing or invalid 'motor' field in config");
        }

        // Parse wheel
        if (!json.contains("wheel") || !json["wheel"].isDouble()) {
            throw std::runtime_error("Missing or invalid 'wheel' field in config");
        }

        // Parse IOs
        if (!json.contains("IO") || !json["IO"].isObject()) {
            throw std::runtime_error("Missing or invalid 'IO' field in config");
        }

        auto motor_arr = json["motor"].toArray();
        QSet<int> motor_logic_ids;
        for (int i = 0; i < motor_arr.size(); ++i) {
            QJsonObject motorDataObj = motor_arr[i].toObject();
            try {
                int logic_id = motorDataObj.value("logic_id").toInt();
                if (motor_logic_ids.find(logic_id) != motor_logic_ids.end()) {
                    throw std::runtime_error("Duplicate motor logic_id in config");
                }
                motor_logic_ids.insert(logic_id);

                uint32_t ecat_id = motorDataObj.value("ECAT_id").toInt();
                double running_speed = motorDataObj.value("running_speed").toDouble();
                double max_speed = motorDataObj.value("max_speed").toDouble();
                double min_speed = motorDataObj.value("min_speed").toDouble();
                double acceleration = motorDataObj.value("acceleration").toDouble();
                double emg_deceleration = motorDataObj.value("emg_deceleration").toDouble();
                double smooth_deceleration = motorDataObj.value("smooth_deceleration").toDouble();
                double position = motorDataObj.value("position").toDouble();
                double negative_limit = motorDataObj.value("negative_limit").toDouble();
                INT32 zero_position = motorDataObj.value("zero_position").toInt();
                double positive_limit = motorDataObj.value("positive_limit").toDouble();
                double ratio = motorDataObj.value("ratio").toDouble();
                double follow_ratio = motorDataObj.value("follow_ratio").toDouble();
                double torque_limit = motorDataObj.value("torque_limit").toDouble();
                double encoder_resolution_counter =
                    motorDataObj.value("encoder_resolution_counter").toDouble();
                double displacement_equivalent = motorDataObj.value("displacement_equivalent").toDouble();

                config_.motor_config[logic_id] = MOTOR_DATA{
                    .physical_id = static_cast<UINT32>(i),
                    .ECAT_id = ecat_id,
                    .acceleration = acceleration,
                    .emg_deceleration = emg_deceleration,
                    .smooth_deceleration = smooth_deceleration,
                    .max_speed = max_speed,
                    .min_speed = min_speed,
                    .running_speed = running_speed,
                    .negative_limit = negative_limit,
                    .positive_limit = positive_limit,
                    .zero_position = zero_position,
                    .position = position,
                    .ratio = ratio,
                    .follow_ratio = follow_ratio,
                    .torque_limit = torque_limit,
                    .encoder_resolution_counter = encoder_resolution_counter,
                    .displacement_equivalent = displacement_equivalent
                };
            } catch (...) {
                throw std::runtime_error("Invalid motor data in config");
            }
        }
        QJsonObject ioObj = json["IO"].toObject();

        // Parse digital_IO
        if (!ioObj.contains("digital_IO") || !ioObj["digital_IO"].isArray()) {
            throw std::runtime_error("Missing or invalid 'digital_IO' field in config");
        }
        QJsonArray digitalIoArr = ioObj["digital_IO"].toArray();
        QSet<int> digitalIoValues;
        for (int i = 0; i < digitalIoArr.size(); ++i) {
            if (!digitalIoArr[i].isDouble()) {
            throw std::runtime_error("Invalid digital_IO entry in config");
            }
            int digitalIoValue = digitalIoArr[i].toInt();
            if (digitalIoValues.find(digitalIoValue) != digitalIoValues.end()) {
            throw std::runtime_error("Duplicate digital_IO value in config");
            }
            digitalIoValues.insert(digitalIoValue);
            config_.io_config.digital_logic_to_physical[i] = digitalIoValue;
        }

        // Parse valve_IO
        if (!ioObj.contains("valve_IO") || !ioObj["valve_IO"].isArray()) {
            throw std::runtime_error("Missing or invalid 'valve_IO' field in config");
        }
        QJsonArray valveIoArr = ioObj["valve_IO"].toArray();
        QSet<int> valveIoValues;
        for (int i = 0; i < valveIoArr.size(); ++i) {
            if (!valveIoArr[i].isDouble()) {
            throw std::runtime_error("Invalid valve_IO entry in config");
            }
            int valveIoValue = valveIoArr[i].toInt();
            if (valveIoValues.find(valveIoValue) != valveIoValues.end()) {
            throw std::runtime_error("Duplicate valve_IO value in config");
            }
            valveIoValues.insert(valveIoValue);
            config_.io_config.valve_logic_to_physical[i] = valveIoValue;
        }

        // Parse valve
        if (!ioObj.contains("valve") || !ioObj["valve"].isArray()) {
            throw std::runtime_error("Missing or invalid 'valve' field in config");
        }
        QJsonArray valveArr = ioObj["valve"].toArray();
        QSet<int> valveValues;
        for (int i = 0; i < valveArr.size(); ++i) {
            int valveValue = valveArr[i].toInt();
            if (valveValues.find(valveValue) != valveValues.end()) {
            throw std::runtime_error("Duplicate valve value in config");
            }
            valveValues.insert(valveValue);
            config_.io_config.valve_station[i] = valveValue;
        }

        config_.wheel_config.start_length_ref = json["wheel"].toDouble();
    }
};