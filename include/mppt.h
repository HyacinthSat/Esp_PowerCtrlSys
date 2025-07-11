// MPPT算法头文件
#pragma once

// MPPT算法类型
enum class MPPTType {
    P_O,    // 扰动观察法
    INC     // 电导增量法
};

// MPPT参数结构体
struct MPPTParams {
    float vin;   // 输入电压
    float iin;   // 输入电流
    float vout;  // 输出电压
    float iout;  // 输出电流
};

// 初始化MPPT
void mppt_init(MPPTType type);
// 执行一次MPPT算法，返回占空比(0~1)
float mppt_step(const MPPTParams& params);
