volatile int encoderPostion;

void EncoderMonitorA() {
  if (digitalRead(2) == digitalRead(3)) {
    encoderPostion++;
  } else {
    encoderPostion--;
  }
}

void EncoderMonitor() {
  if (digitalRead(2) == digitalRead(3)) {
    encoderPostion--;
  } else {
    encoderPostion++;
  }
}

void EncoderInitialize() {
  pinMode(2,INPUT);
  pinMode(3, INPUT);
  attatchInterrupt(digitalPinToInterrupt(2), EncoderMonitorA, CHANGE);
  attatchInterrupt(digitalPinToInterrupt(3), EncoderMonitorB, CHANGE);
}
