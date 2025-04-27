#include <HomeSpan.h>

#include <WiFiUdp.h>
#include <WakeOnLan.h>
#include <Preferences.h>

WiFiUDP UDP;
WakeOnLan WOL(UDP);
Preferences preferences;

#include "hswol.h"

void setup() {
  Serial.begin(115200);
  preferences.begin("config");

  // 初始化 HomeSpan
  homeSpan.enableOTA("ota");
  homeSpan.begin(Category::Switches, "HSWOL", "HomeSpan-HSWOL");

  // 设置第一台设备（PVE主机）
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new HSWOL("E0:51:D8:11:3D:CE");

  // 设置第二台设备（出租屋电脑）
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new HSWOL("74:56:3C:D3:65:74");

  // 后台自动更新
  homeSpan.autoPoll();
}

void loop() {}
