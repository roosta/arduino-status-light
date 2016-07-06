// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS 16

// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

/* Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN); */

int delayval = 500; // delay for half a second

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(4, 4, 6,
    NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG);

void setup() {
  matrix.begin();
}

void test() {
  /* print("aslkdj"); */
  /* system("/usr/bin/sensors"); */
}
void loop() {
  matrix.drawRect(0, 0, 4, 4, BLUE);
  matrix.show();

  matrix.drawRect(1, 1, 2, 2, MAGENTA);
  matrix.show();
  delay(500);

  matrix.drawRect(1, 1, 2, 2, BLACK);
  matrix.show();
  delay(500);
  /* matrix.fillScreen(0); */
  /* matrix.drawPixel(0, 0, BLUE); */

}
