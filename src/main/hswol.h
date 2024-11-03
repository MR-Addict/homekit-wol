struct HSWOL : Service::Switch {
private:
  const char* mac;
  SpanCharacteristic* power;

public:
  HSWOL(const char* mac)
    : Service::Switch() {
    this->mac = mac;
    power = new Characteristic::On();
  }

  boolean update() {
    // 检查 HomeKit 是否发送了一个开机的请求
    if (power->getNewVal()) {
      Serial.println(String("Waking up machine: ") + mac);
      WOL.calculateBroadcastAddress(WiFi.localIP(), WiFi.subnetMask());
      return WOL.sendMagicPacket(mac);
    } else return false;
  }

  void loop() {
    // 检测到开机请求，并且距离上次修改超过了3秒钟，复原按钮
    if (power->getVal() && power->timeVal() > 3000) power->setVal(false);
  }
};
