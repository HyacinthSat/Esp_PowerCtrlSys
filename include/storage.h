// 储能管理接口
#pragma once

enum class StorageType {
    Battery,
    SuperCap
};

struct StorageStatus {
    float voltage;
    float current;
    float soc; // 剩余容量百分比
};

// 初始化储能系统
void storage_init();
// 获取储能状态
StorageStatus storage_get_status(StorageType type);
