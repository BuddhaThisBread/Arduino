#include "EncoderMonitor.h"
#include <LiquidCrystal.h>

LiquidCrystal LcdDriver(A5,A4, 5, 6, 7, 8);

unsigned long timer = millis();

void setup() {
  LcdDriver.begin(16,2);
  LcdDriver.clear();
  EncoderInitialize();
}

void loop() {
  //EncoderMonitorA();
  //EncoderMonitorB();
  LcdDriver.setCursor(0,1);
  if (millis() - timer >= 100) {
    LcdDriver.print(encoderPostion);
  }
}
