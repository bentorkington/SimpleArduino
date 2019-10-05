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
const int NUM_POINTS = 8;
const int POINT_SPREAD = 50;
//const OLED_Colour COLOURS[NUM_CHANNELS] = { RED, GREEN, BLUE };


float zoom = 1 / 3.0E-5;
float moveX = -0.74529;
float moveY = 0.113075;
int maxIter = 200;
struct point {
   float x, y, z;
   int col;
};

float c;

struct point Points[NUM_POINTS] = {
  {-1, -1, -1, 0}, 
  {-1, -1, 1, 1}, 
  {-1, 1, -1, 2}, 
  {-1, 1, 1, 3}, 
  {1, -1, -1, 4}, 
  {1, -1, 1, 5}, 
  {1, 1, -1, 6}, 
  {1, 1, 1, 7}, 

};
  OLED_Colour COLOURS[NUM_CHANNELS];



void setup() {
//  for (int i=0; i<NUM_POINTS; ++i) 
//  {
//    Points[i].x = random(-POINT_SPREAD, POINT_SPREAD);
//    Points[i].y = random(-POINT_SPREAD, POINT_SPREAD);
//    Points[i].z = random(-POINT_SPREAD, POINT_SPREAD);
//    Points[i].col = random(NUM_CHANNELS);
//  }
  
  oled.begin();
  oled.selectFont(System5x7);

  for (byte i = 0; i<NUM_CHANNELS; ++i) {
    COLOURS[i] = { 255 * i / NUM_CHANNELS, 0, 255 * (255 - i)  / NUM_CHANNELS};
  }
  for (int i = 0; i<128; ++i) {
     OLED_Colour col = {i, 0, 0};  
     oled.setPixel(i, 0, col);
  }
  for (int i = 0; i<128; ++i) {
     OLED_Colour col = {i + 128, 0, 0};  
     oled.setPixel(i, 2, col);
  }
  for (int i = 0; i<128; ++i) {
     OLED_Colour col = {0,i, 0};  
     oled.setPixel(i, 4, col);
  }
  for (int i = 0; i<128; ++i) {
     OLED_Colour col = {0,i + 128, 0};  
     oled.setPixel(i, 6, col);
  }
  for (int i = 0; i<128; ++i) {
     OLED_Colour col = {0,0,i};  
     oled.setPixel(i, 8, col);
  }
  for (int i = 0; i<128; ++i) {
     OLED_Colour col = {0,0,i + 128};  
     oled.setPixel(i, 10, col);
  }
  oled.drawFilledBox(0, 12, 15, 127, {31, 63, 31});
  oled.drawFilledBox(16, 12, 31, 127, {31, 63, 0});
  oled.drawFilledBox(32, 12, 47, 127, {0, 63, 31});
  oled.drawFilledBox(48, 12, 63, 127, {0, 63, 0});
  oled.drawFilledBox(64, 12, 79, 127, {31, 0, 31});
  oled.drawFilledBox(80, 12, 95, 127, {31, 0, 0});
  oled.drawFilledBox(96, 12, 111, 127, {0, 0, 31});
  oled.drawFilledBox(112, 12, 127, 127, {0, 0, 0});
}

void loop() {
}


