// 通信接口
#pragma once

enum class CommsType {
    UART,
    I2C,
    SPI
};

// 初始化通信
void comms_init(CommsType type);
// 发送数据
void comms_send(const char* data, int len);
// 接收数据
int comms_receive(char* buf, int maxlen);
