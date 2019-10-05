/*
 * Plot a chart reading of analog input values in realtime, with the
 * raw numeric values written in text below
 */

const byte pin_cs = 7;
const byte pin_dc = 2;
const byte pin_reset = 3;

#include <SPI.h>
#include "FTOLED.h"
#include "fonts/SystemFont5x7.h"

OLED oled(pin_cs, pin_dc, pin_reset);
// Text box takes up bottom 32 characters of the display (ie 4 rows)
//OLED_TextBox box(oled, 0, 0, 128, 32);

const int NUM_CHANNELS = 64;

//const OLED_Colour COLOURS[NUM_CHANNELS] = { RED, GREEN, BLUE };

float zoom = 1 / 3.0E-5;
float moveX = -0.74529;
float moveY = 0.113075;
int maxIter = 200;

void setup() {
  oled.begin();
  oled.selectFont(System5x7);

OLED_Colour COLOURS[NUM_CHANNELS];
  for (int i = 0; i<NUM_CHANNELS; ++i) {
    COLOURS[i] = { 31 * i / NUM_CHANNELS, 0, 31 * (31 - i)  / NUM_CHANNELS};
  }

  for (int y = 0; y < 127; ++y) {
    for (int x = 0; x < 127; ++x) {     
          oled.setPixel(x, y, {y >> 3, y >> 2, y >> 3});
    }
  }
}

void loop() {
  
}
