#include "HomeSpan.h"
#include "WOL.h"

void setup() {
  Serial.begin(115200);

  homeSpan.enableOTA("ota");
  homeSpan.begin(Category::Switches, "WOL", "HomeSpan-WOL");

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();

  new WOL();

  homeSpan.autoPoll();
}

void loop() {}
