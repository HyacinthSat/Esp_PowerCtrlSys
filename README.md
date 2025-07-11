# Esp_PowerCtrlSys
电源分系统主控算法与控制代码测试项目
起始时间：2025-7-11
开发人员：Shjdness(BG6HVQ)

----------------------------------------------------------------------------
此处为项目框架
EspPowerCtrlSys/
│
├── platformio.ini                # PlatformIO配置
├── README.md                     # 项目说明
├── include/
│   ├── mppt.h                    # MPPT算法头文件
│   ├── sepic.h                   # SEPIC转换器相关
│   ├── pdu.h                     # PDU配电单元接口
│   ├── storage.h                 # 储能管理接口
│   ├── sensors.h                 # 传感器采集接口
│   └── comms.h                   # 通信接口
│
├── lib/
│   ├── mppt/                     # MPPT算法实现
│   ├── sepic/                    # SEPIC控制实现
│   ├── pdu/                      # PDU实现
│   ├── storage/                  # 储能管理实现
│   ├── sensors/                  # 传感器采集实现
│   └── comms/                    # 通信实现
│
├── src/
│   └── main.cpp                  # 主控入口，任务调度
│
├── test/
│   └── test_main.cpp             # 单元测试/功能测试
└──