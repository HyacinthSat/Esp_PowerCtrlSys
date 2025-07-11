#include "sepic.h"
#include <Arduino.h>

void sepic_init() {
    // 初始化PWM输出，假设使用GPIO 5
    pinMode(5, OUTPUT);
    // 这里可初始化PWM通道
}

void sepic_set_duty(float duty) {
    // duty范围0~1，转换为PWM值
    int pwm_val = (int)(duty * 255.0f);
    pwm_val = constrain(pwm_val, 0, 255);
    analogWrite(5, pwm_val);
}
