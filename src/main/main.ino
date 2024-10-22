#include <HomeSpan.h>

#include <WiFiUdp.h>
#include <WakeOnLan.h>
#include <Preferences.h>

WiFiUDP UDP;
WakeOnLan WOL(UDP);
Preferences preferences;

#include "utils.h"
#include "hswol.h"

void setup() {
  Serial.begin(115200);
  preferences.begin("config");

  // 初始化 HomeSpan
  homeSpan.enableOTA("ota");
  homeSpan.begin(Category::Switches, "HSWOL", "HomeSpan-HSWOL");

  // 设置默认的参数信息
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new HSWOL();

  new SpanUserCommand('m', "<mac> - set MAC address", setMacCommand);  // 设置终端命令
  homeSpan.autoPoll();                                                 // 后台自动更新
}

void loop() {}
