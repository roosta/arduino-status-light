// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS 16

#define mw 4
#define mh 4

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

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(mw, mh, PIN,
    NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  matrix.setBrightness(75);
  matrix.begin();
  while (!Serial);
}

void cpu_usage(int incoming) {

  // read the incoming byte:
  if (incoming < 25) {
    matrix.drawRect(3, 0, 1, 4, BLACK);
    matrix.drawRect(3, 3, 1, 1, BLUE);
    matrix.show();
  }
  else if (incoming >= 25 && incoming <= 50) {
    matrix.drawRect(3, 0, 1, 4, BLACK);
    matrix.drawRect(3, 2, 1, 2, BLUE);
    matrix.show();
  }
  else if (incoming > 50 && incoming <= 75) {
    matrix.drawRect(3, 0, 1, 4, BLACK);
    matrix.drawRect(3, 1, 1, 3, BLUE);
    matrix.show();
  }
  else if (incoming > 75) {
    matrix.drawRect(3, 0, 1, 4, BLACK);
    matrix.drawRect(3, 0, 1, 4, BLUE);
    matrix.show();
  }
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    unsigned char inputBuffer[3];
    Serial.readBytes(inputBuffer, sizeof(inputBuffer));
    matrix.drawPixel(inputBuffer[0], inputBuffer[1], inputBuffer[2]);
  }
}
