#include <SPI.h>

int DisplayRow, DisplayColumn, datz;
unsigned long timer;

#define MAX7219_TEST 0x0f00 // display in Test mode
#define MAX7219_BRIGHTNESS 0x0a00 // set brightness of display
#define MAX7219_SCAN_LIMIT 0x0b00 // set scan limit
#define MAX7219_DECODE_MODE 0x0900 // set chip to accept bit patters
#define MAX7219_SHUTDOWN 0x0C00 //  shutdown chip

void SPI_16(int data) {
  digitalWrite(A0,LOW); // set load to 0, PIN 12 on MAX7219 
  SPI.transfer16(data); // Transfer 'data' to shift register, on rising edge of CLK
  digitalWrite(A0,HIGH); // set load to 1,  cutting off data flow
}

void setup() {
  SPI.begin();
  pinMode(A0,OUTPUT); // D10 is Slave Select
  digitalWrite(A0, HIGH);
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0)); // 
  
  SPI_16(MAX7219_TEST + 0x01); // turn on leds
  delay(100);    
  SPI_16(MAX7219_TEST + 0x00);              
  SPI_16(MAX7219_DECODE_MODE + 0x00); // disable BCD mode
  SPI_16(MAX7219_BRIGHTNESS + 0x03); // lower intensity
  SPI_16(MAX7219_SCAN_LIMIT + 0x0f); // scan all digits
  SPI_16(MAX7219_SHUTDOWN + 0x01); // turn off chip
  
  DisplayColumn = 0; // columns 1-7
  DisplayRow = 0x00C5; // effect pattern generated
  timer = millis(); // set timer
}

void loop() {
  if (millis() - timer >= 500) { // if .5 seconds passed
    DisplayColumn++;
    if (DisplayColumn > 8) { // if there's more than 8 (only 8 on board), reset to one
      DisplayColumn = 1;
    }
    if (DisplayRow & 0x0080) { // if row 7, shift row to left by one
      DisplayRow = DisplayRow << 1;
    }
    else {
      DisplayRow = (DisplayRow << 1 ) + 1; // if any other row, shift 
    }
    datz = DisplayRow & 0x00ff; // mask off DisplayRow, save bottom bits
    SPI_16((DisplayColumn << 8) + datz);
    timer += 500;
  }
}
