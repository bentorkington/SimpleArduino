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
 
}

void loop() {
  OLED_Colour black = {0, 0, 0};
   //oled.fillScreen(black);

   float a11 = 20 * sin(c);
   float a12 = 0;
   float a13 = 20 * cos(c);
   
   float a21  = 0;
   float a22  = 20;
   float a23  = 0;

   float a31  = 20 * -sin(c);
   float a32  = 0;
   float a33  = 20 * cos(c);
    
  for (int i = 0; i<NUM_POINTS; ++i)
{
   float nx = a11*Points[i].x + a12*Points[i].y + a13*Points[i].z;
   float ny = a21*Points[i].x + a22*Points[i].y + a23*Points[i].z;
   float nz = a31*Points[i].x + a32*Points[i].y + a33*Points[i].z;

    int sx = (nx / sqrt(nz + 26)) + 64;
    int sy = (ny / sqrt(nz + 26)) + 64;


    
    if (sx >= 0 && sx < 127 && sy >= 0 && sy < 127) {
      oled.setPixel(sx, sy, COLOURS[Points[i].col]);
    }
  delay(20);
  c += 0.005;
}
  
}
