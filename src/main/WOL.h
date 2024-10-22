struct WOL : Service::Switch {
  SpanCharacteristic* power;

  WOL()
    : Service::Switch() {
    power = new Characteristic::On();
  }

  boolean update() {
    // 检查 HomeKit 是否发送了一个开机的请求
    if (power->getNewVal()) {
      Serial.println("New Push State");
    }
    return true;
  }

  void loop() {
    // 检测到开机请求，并且等待了3秒钟，关闭请求
    if (power->getVal() && power->timeVal() > 10000) {
      power->setVal(false);
    }
  }
};
