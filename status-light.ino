#include <SPI.h>
#include <FastLED.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUM_LEDS 16
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


void draw_pixel(int pos, int color) {
  leds[0] = CRGB::Red;
  FastLED.show();
}

void loop() {

  // Turn the first led red for 1 second
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);

  // Set the first led back to black for 1 second
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(1000);
  // send data only when you receive data:
  /* if (Serial.available() > 0) { */
  /*   unsigned char inputBuffer[3]; */
  /*   Serial.readBytes(inputBuffer, sizeof(inputBuffer)); */
  /*   /\* draw_pixel(inputBuffer[0], inputBuffer[1], inputBuffer[2]); *\/ */

  /*   Serial.print("x:"); */
  /*   Serial.println(inputBuffer[0], DEC); */
  /*   Serial.print("y:"); */
  /*   Serial.println(inputBuffer[1], DEC); */
  /*   Serial.print("color:"); */
  /*   Serial.println(inputBuffer[2], DEC); */
  /* } */
}
