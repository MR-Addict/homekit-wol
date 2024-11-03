# HomeKit Wake Up Your PC

This is an ESP32 homespan project that allows you to wake up your PC from sleep using Apple HomeKit.

## Setup your PC MAC

Open [main.ino](src/main/main.ino) and add your PC MAC address like this:

```cpp
// 设置第一台设备
new SpanAccessory();
new Service::AccessoryInformation();
new Characteristic::Identify();
new HSWOL("E0:51:D8:11:3D:CE");

// 设置第二台设备
new SpanAccessory();
new Service::AccessoryInformation();
new Characteristic::Identify();
new HSWOL("74:56:3C:D3:65:74");
```

## Add to your Home app

Follow up the **serial** output to setup your WiFi network and add to your Home app.

Default pair pin is **HSPN**, and default pair code is **466-37-726**.

[Reference](https://github.com/HomeSpan/HomeSpan/blob/master/docs/QRCodes.md)
