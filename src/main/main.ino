#include "HomeSpan.h"
#include "WOL.h"

const char* mac = "30-89-4A-C9-73-72";

void setup() {
  Serial.begin(115200);

  homeSpan.enableOTA("ota");
  homeSpan.begin(Category::Lighting, "WOL", "HomeSpan-WOL");

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();

  new WOL(mac);

  homeSpan.autoPoll();
}

void loop() {}
