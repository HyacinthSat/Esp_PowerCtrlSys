#include "sensors.h"
#include <Arduino.h>

void sensors_init() {
    // 初始化ADC等硬件接口
}

float sensors_read(SensorType type) {
    switch(type) {
        case SensorType::PV_Voltage:
            // 模拟光伏电压采集
            return 5.0f + random(-10, 10) * 0.01f;
        case SensorType::PV_Current:
            // 模拟光伏电流采集
            return 0.8f + random(-10, 10) * 0.01f;
        case SensorType::Temp:
            // 模拟温度采集
            return 25.0f + random(-10, 10) * 0.1f;
        default:
            return 0.0f;
    }
}
