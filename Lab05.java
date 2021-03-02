/*#include <LiquidCrystal.h>

void setup() {
  // initialize display
  LiquidCrystal LcdDriver(11, 9, 5, 6, 7, 8);
  LcdDriver.begin(16,2);
  LcdDriver.clear();
  // create timer, iterates every second
  int count = 0; 
  long sTimer = millis();
  }

void loop() {
  if (millis() - sTimer >= 1000) {
    count++;
    // print count which incremints every second
    LcdDriver.print(count, BIN);
    sTimer += 1000;
  }
}*/

#include <LiquidCrystal.h>

void setup() {
  // initialize display
  LiquidCrystal LcdDriver(11, 9, 5, 6, 7, 8);
  LcdDriver.begin(16,2);
  LcdDriver.clear();
  // create timer, iterates every second
  int count = 0; 
  long sTimer = millis();
  long stopWatch = sTimer;
  int count2 = 0;
  }

void loop() {
  if (millis() - sTimer >= 1000) {
    count++;
    // print count which incremints every second
    LcdDriver.print(count, BIN);
    sTimer += 1000;
  }
  if (millis() - stopWatch >= 100) {
    if (digitalRead(4) == HIGH) {
      count2 = 0;
    } else if (digitalRead(4) == LOW) {
      count2++;
      LcdDriver.clear();
      LcdDriver.print(count2,BIN);
    }
    stopWatch += 100;
  }
}
