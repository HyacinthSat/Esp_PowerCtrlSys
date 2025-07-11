// 传感器采集接口
#pragma once

enum class SensorType {
    PV_Voltage,
    PV_Current,
    Temp,
    Other
};

// 初始化传感器
void sensors_init();
// 采集传感器数据
float sensors_read(SensorType type);
