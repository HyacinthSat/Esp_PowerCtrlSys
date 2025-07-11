#include "storage.h"

static StorageStatus battery = {3.7f, 0.5f, 80.0f}; // 模拟电池初始状态
static StorageStatus supercap = {2.5f, 0.2f, 60.0f}; // 模拟超级电容初始状态

void storage_init() {
    // 可在此初始化硬件接口
    // 这里只做模拟
}

StorageStatus storage_get_status(StorageType type) {
    if (type == StorageType::Battery) {
        // 可在此采集真实数据
        return battery;
    } else {
        return supercap;
    }
}
