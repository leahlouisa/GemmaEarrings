// Low power NeoPixel earrings example.  Makes a nice blinky display
// with just a few LEDs on at any time...uses MUCH less juice than
// rainbow display!

#include <Adafruit_NeoPixel.h>

#define PIN 0

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(32, PIN);

uint8_t  offset = 0; // Position of spinny eyes
uint8_t colorCounter  = 0; // Start counting those colors

void setup() {
  pixels.begin();
  pixels.setBrightness(60); // 1/3 brightness
}

void loop() {
  uint8_t  i;
  //uint32_t currentColor = Wheel(colorCounter);  UC FOR RAINBOW

    uint8_t  light1 = (offset+0)%16;
    uint8_t  light2 = (offset+4)%16;
    uint8_t  light3 = (offset+8)%16;
    uint8_t  light4 = (offset+12)%16;
    pixels.setPixelColor(light1, 0xff0000);
    pixels.setPixelColor(light2, 0xff0000);
    pixels.setPixelColor(light3, 0xff0000);
    pixels.setPixelColor(light4, 0x000080);
  

  pixels.show();
  offset++;
  if(offset > 15) offset=0;
  //colorCounter++;  UNCOMMENT FOR RAINBOW
  //if(colorCounter > 255) colorCounter=0;  UNCOMMENT FOR RAINBOW
  delay(100);
  for(i=0; i<16; i++) pixels.setPixelColor(i, 0);
  pixels.show();

}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
