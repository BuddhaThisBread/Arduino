int DisplayRow, DisplayColumn;

#define MAX7219_TEST 0x0f00 // display in Test mode
#define MAX7219_BRIGHTNESS 0x0a00 // set brightness of display
#define MAX7219_SCAN_LIMIT 0x0b00 // set scan limit
#define MAX7219_DECODE_MODE 0x0900 // set chip to accept bit patters
#define MAX7219_SHUTDOWN 0x0C00 //  shutdown chip

void SPI_16(int data) {
  // set load to 0, PIN 12 on MAX7219 
  // Transfer 'data' to shift register, on rising edge of CLK
  // set load to 1,  cutting off data flow
}

void setup() {
  // PIN 12 on MAX set to output
  SPI_16(MAX7219_TEST + 0x01); // turn on leds
  delay(100);                  
  SPI_16(MAX7219_DECODE_MODE + 0x00); // disable BCD mode
  SPI_16(MAX7219_BRIGHTNESS + 0x03); // lower intensity
  SPI_16(MAX7219_SCAN_LIMIT + 0x0f); // scan all digits
  SPI_16(MAX7219_SHUTDOWN + 0x01); // turn off chip
  DisplayColumn = 0; // columns 1-7
  DisplayRow = 0x0080; // effect pattern generated
}

void loop() {
  
}
