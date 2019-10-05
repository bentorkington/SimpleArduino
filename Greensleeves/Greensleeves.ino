/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_A3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_B3,       //8
  NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_A3, NOTE_A3, NOTE_GS3, NOTE_A3,      // 8

  NOTE_B3, NOTE_GS3, NOTE_E3, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,    //8
  NOTE_E4, NOTE_D4, NOTE_B3, NOTE_G3, NOTE_A3, NOTE_B3,                           // 6

  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_A3, NOTE_A3,      //8

  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_G3, NOTE_A3, NOTE_B3,  //9
  NOTE_C4, NOTE_A3, NOTE_A3, NOTE_GS3, NOTE_A3, NOTE_B3, NOTE_GS3, NOTE_E3,         //8

  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_G3, NOTE_A3, 
  NOTE_B3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_A3, NOTE_A3,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
// in quaver lengths
int noteDurations[] = {
  2, 4, 2, 3, 1, 2, 4, 2,
  3, 1, 2, 4, 2, 3, 1, 2,
  
  4, 2, 4, 2, 4, 2, 3, 1,
  2, 4, 2, 3, 1, 2,

  3, 1, 2, 3, 1, 2, 6, 6,
  6, 3, 1, 2, 4, 2, 3, 1, 2,

  4, 2, 3, 1, 2, 4, 2, 6,

  6, 3, 1, 2, 4, 2, 3, 1, 2, 
  3, 1, 2, 3, 1, 2, 6, 6,
  
};

void setup() {
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(noteDurations) / 2; thisNote++) {

    int noteDuration = 150 * noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.10;
    delay(pauseBetweenNotes);
    digitalWrite(12, 0);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
