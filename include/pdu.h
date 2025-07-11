// PDU配电单元接口
#pragma once

// 初始化PDU
void pdu_init();
// 设置某路输出开关
void pdu_set_channel(int channel, bool enable);
// 查询某路状态
bool pdu_get_channel_status(int channel);
