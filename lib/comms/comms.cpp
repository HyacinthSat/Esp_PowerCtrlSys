#include "comms.h"
#include <Arduino.h>

static CommsType comms_type = CommsType::UART;

void comms_init(CommsType type) {
    comms_type = type;
    if (type == CommsType::UART) {
        Serial.begin(115200);
    }
    // 其他类型可扩展
}

void comms_send(const char* data, int len) {
    if (comms_type == CommsType::UART) {
        Serial.write(data, len);
    }
    // 其他类型可扩展
}

int comms_receive(char* buf, int maxlen) {
    int count = 0;
    if (comms_type == CommsType::UART) {
        while (Serial.available() && count < maxlen) {
            buf[count++] = Serial.read();
        }
    }
    // 其他类型可扩展
    return count;
}
