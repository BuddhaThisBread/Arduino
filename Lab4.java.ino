/*char Alpha = 'A';
char Number = '0';

unsigned long Timer;

void setup() {
  Serial.begin(9600);
  Timer = millis();
}

void loop() {
  if (millis() - Timer >= 500) {
    Serial.print(Alpha);
    Serial.print(Number);
    Alpha += 1;
    Number += 1;
    if ( Alpha > 'Z')
      Alpha = 'A';

    if (Number > '9')
      Number = '0';
      
    Timer += 500;
  }
 
  if (Serial.available() > 0) {
    if (Serial.read() == 'R') {
      Alpha = 'A';
      Number = '0';
    }
  }
}*/

char Alpha = 'A';
char Number = '0';

unsigned long Timer;

void setup() {
  Serial.begin(9600);
  Timer = millis();
}

void loop() {
  if (millis() - Timer >= 500) {
    Serial.print(Alpha);
    Timer += 500;
  }
}
