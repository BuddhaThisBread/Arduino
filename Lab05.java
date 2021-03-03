/*#include <LiquidCrystal.h>

// initialize display
LiquidCrystal LcdDriver(A5, A4, 5, 6, 7, 8);

// create timer, iterates every second
int count = 0; 
long sTimer = millis();

void setup() {
  LcdDriver.begin(16,2);
  LcdDriver.clear();
  }

void loop() {
  if (millis() - sTimer >= 1000) {
    count++;
    // print count which incremints every second
    LcdDriver.print(count);
    sTimer += 1000;
  }
}


*/

#include <LiquidCrystal.h>

LiquidCrystal LcdDriver(A5, A4, 5, 6, 7, 8);

// create timer, iterates every second
int count = 0; 
long sTimer = millis();
long stopWatch = sTimer;
int count2 = 0;

void setup() {
  LcdDriver.begin(16,2);
  LcdDriver.clear();
  }

void loop() {
  if (millis() - sTimer >= 1000) {
    count++;
    // print count which incremints every second
    LcdDriver.print(count);
    sTimer += 1000;
  }
  if (millis() - stopWatch >= 100) {
    if (digitalRead(4) == HIGH) {
      count2 = 0;
    } else if (digitalRead(4) == LOW) {
      LcdDriver.clear();
      count2++;
      LcdDriver.print(count2);
    }
    stopWatch += 100;
  }
}
