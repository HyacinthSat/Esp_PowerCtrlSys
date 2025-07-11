#include "mppt.h"
#include <Arduino.h>
static MPPTType g_type = MPPTType::INC;
static float last_v = 0.0f, last_i = 0.0f, last_duty = 0.5f;

void mppt_init(MPPTType type) {
    g_type = type;
    last_v = 0.0f;
    last_i = 0.0f;
    last_duty = 0.5f;
}

float mppt_step(const MPPTParams& params) {
    float duty = last_duty;
    if (g_type == MPPTType::INC) {
        // 电导增量法
        float dv = params.vin - last_v;
        float di = params.iin - last_i;
        if (dv != 0) {
            float dP_dV = di + params.iin * (di / dv);
            if (dP_dV > 0) duty += 0.01f;
            else if (dP_dV < 0) duty -= 0.01f;
        }
    } else {
        // 扰动观察法（简单实现）
        float power = params.vin * params.iin;
        float last_power = last_v * last_i;
        if (power > last_power) duty += 0.01f;
        else duty -= 0.01f;
    }
    duty = constrain(duty, 0.0f, 1.0f);
    last_v = params.vin;
    last_i = params.iin;
    last_duty = duty;
    return duty;
}
