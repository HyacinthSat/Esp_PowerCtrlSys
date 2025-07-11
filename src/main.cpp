#include <Arduino.h>
#include "mppt.h"
#include "sepic.h"
#include "pdu.h"
#include "storage.h"
#include "sensors.h"
#include "comms.h"

// 全局参数
MPPTType mppt_type = MPPTType::INC;

void setup() {
    Serial.begin(115200);
    sensors_init();
    storage_init();
    sepic_init();
    mppt_init(mppt_type);
    pdu_init();
    comms_init(CommsType::UART);
}

void loop() {
    // 采集光伏参数
    MPPTParams params;
    params.vin = sensors_read(SensorType::PV_Voltage);
    params.iin = sensors_read(SensorType::PV_Current);
    // 假设输出参数可由储能系统获取
    StorageStatus bat = storage_get_status(StorageType::Battery);
    params.vout = bat.voltage;
    params.iout = bat.current;

    // MPPT算法计算占空比
    float duty = mppt_step(params);
    sepic_set_duty(duty);

    // PDU分配（示例：通道0供电）
    pdu_set_channel(0, true);

    // 通信发送状态
    char buf[64];
    snprintf(buf, sizeof(buf), "VIN:%.2f IIN:%.2f DUTY:%.2f", params.vin, params.iin, duty);
    comms_send(buf, strlen(buf));

    delay(1000); // 1秒循环
}