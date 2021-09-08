# Tuya IoTOS Embedded Mcu Demo Wifi Ble GD32_OLED

[English](./README.md) | [中文](./README_zh.md)

## Introduction  

This Demo uses the Tuya smart cloud platform, Tuya smart APP, OLEDand IoTOS Embedded MCU SDK to realize a  gets the network time and displays it

The implemented features include:

+ Gets the network time and displays it


## Quick start  

### Compile & Burn
+ Download Tuya IoTOS Embeded Code
+ Execute the Project.uvprojx file
+ Click Compile in the software and complete the download


### File introduction 

```
├── Application
│   ├── main.c
│   ├── gd32e23x_it.c
│   ├── systick.c
│   ├── gd32e23x_it.h
│   ├── systick.h
│   ├── gd32e23x_libopt.h
├── GD32E23x_Firmware_Library
│   ├── CMSIS
        ├── Include
           │   ├──gd32e23x.h
           │   ├──system_gd32e23x.h
        ├── Source
           │   ├──startup_gd32e23x.s
           │   ├──system_gd32e23x.h        
│   ├── GD32E23x_standard_peripheral
        ├── Include
        ├── Source
├──User
│   ├── connect_wifi.c
│   ├── delay.c
│   ├── delay.h
│   ├── led.c
│   ├── led.h
│   ├── myiic.c
│   ├── myiic.h
│   ├── oled.c
│   ├── oled.h
│   ├── usart.c
│   ├── usart.h
└── MCU_SDK
    ├── mcu_api.c
    ├── mcu_api.h
    ├── protocol.c
    ├── protocol.h
    ├── system.c
    ├── system.h
    └── wifi.h
```



### Demo entry

Entry file：main.c

Important functions：main()

+ Initialize and configure MCU IO,USART,IIC,OLED,etc. All events are polled and judged in while(1)。



### I/O List  

|   OLED   |  UASRT0  | UASRT1  |    KEY     |
| :------: | :------: | :-----: | :--------: |
| SCL  PB0 | PA9 TXD  | PA2 TXD |    PB8     |
| SDA  PB1 | PA10 RXD | PA3 RXD | Networking |



## Related Documents

 Tuya Demo Center: https://developer.tuya.com/demo



## Technical Support

  You can get support for Tuya by using the following methods:

- Developer Center: https://developer.tuya.com
- Help Center: https://support.tuya.com/help
- Technical Support Work Order Center: [https://service.console.tuya.com](https://service.console.tuya.com/) 

