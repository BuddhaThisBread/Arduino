/*#ifndef "ButtonDebounce_h"
#define "ButtonDebounce_h"
*/
enum buttonStates{buttonStart, buttonIdle, buttonWait, buttonHigh, buttonLow}buttonState;
unsigned long buttonTime;


void buttonInitialize() { // set pin, buttonState to buttonStart
  pinMode(4,INPUT);
  buttonState = buttonStart;
} // end of button initialize

int buttonNextState(int pressed){
  switch(buttonState){
    case(buttonStart): // initialzie program
      buttonState = buttonIdle;
      
    case(buttonIdle): // checks if button is pressed, goes to next state if so
      if (pressed == LOW) { // button pressed
        buttonTime = millis();
        buttonState = buttonWait; // change to buttonWait
        digitalWrite(13, HIGH);
      }
      break;
      
    case(buttonWait): // checks if button is not pressed 
      if (pressed == HIGH){
        buttonState = buttonIdle; // change state to idle if not pressed
        digitalWrite(13, LOW);
      } else if (millis() - buttonTime >= 5) {
        buttonState = buttonLow;
        digitalWrite(13,LOW);
        return 1;
      }
      
    case(buttonLow):
      if (pressed == HIGH){
        buttonState = buttonIdle;
        return 2;
      }
      
    default:
      return 0;
  }
}
//#endif
