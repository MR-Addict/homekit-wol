struct HSWOL : Service::Switch {
  SpanCharacteristic* power;

  HSWOL()
    : Service::Switch() {
    power = new Characteristic::On();
  }

  boolean update() {
    // 检查 HomeKit 是否发送了一个开机的请求
    if (power->getNewVal()) {
      const String mac = preferences.getString("mac");
      if (isValidMacAddress(mac.c_str())) {
        Serial.println("Waking up machine: " + mac);
        WOL.calculateBroadcastAddress(WiFi.localIP(), WiFi.subnetMask());
        WOL.sendMagicPacket(mac.c_str());
      } else return false;  // MAC 地址不合法直接返回false
    }
    return true;
  }

  void loop() {
    // 检测到开机请求，并且距离上次修改超过了3秒钟，复原按钮
    if (power->getVal() && power->timeVal() > 3000) power->setVal(false);
  }
};
