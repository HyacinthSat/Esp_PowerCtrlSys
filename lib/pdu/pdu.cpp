#include "pdu.h"
#include <Arduino.h>

static bool channel_status[4] = {false, false, false, false};

void pdu_init() {
    // 初始化PDU相关硬件，假设4路输出分别为GPIO 10~13
    for (int i = 0; i < 4; ++i) {
        pinMode(10 + i, OUTPUT);
        digitalWrite(10 + i, LOW);
        channel_status[i] = false;
    }
}

void pdu_set_channel(int channel, bool enable) {
    if (channel >= 0 && channel < 4) {
        digitalWrite(10 + channel, enable ? HIGH : LOW);
        channel_status[channel] = enable;
    }
}

bool pdu_get_channel_status(int channel) {
    if (channel >= 0 && channel < 4) {
        return channel_status[channel];
    }
    return false;
}
