#include "ButtonDebounce.h"
void setup() {
  buttonInitialize();
  Serial.begin(9600);
}

void loop() {
  switch(buttonNextState(digitalRead(4))){
    case 0:
      break;
    case 1:
      Serial.println("Button pressed");
      break;
    case 2:
     Serial.println("Button released");
     break;
  }
}
