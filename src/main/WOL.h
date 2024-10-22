struct WOL : Service::StatelessProgrammableSwitch {
  SpanCharacteristic *switchEvent;

  WOL()
    : Service::StatelessProgrammableSwitch() {
    power = new Characteristic::On(false, true);

    new SpanButton(button, SpanButton::TRIGGER_ON_HIGH);
    setLampState(power->getVal());
  }

  void button(int pin, int pressType) override {
    bool state = !power->getVal();
    setLampState(state);
    power->setVal(state);
  }

  boolean update() {
    setLampState(power->getNewVal());
    return true;
  }
};
