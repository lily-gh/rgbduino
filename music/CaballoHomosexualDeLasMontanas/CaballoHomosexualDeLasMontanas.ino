/************************************
 * Caballo Homosexual De Las Montanas
 * Synthesia video: https://www.youtube.com/watch?v=HfInzjSm-jA
************************************/

#include "pitches.h"

// change this to make the song slower or faster
int tempo = 120;

// On RGBduino Uno, pin 8 is used for the built-in buzzer. Change this if using another board
int buzzer = 8;

// Notes of the melody followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on.
// Negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  // chorus
  // caballo homosexual de las montanas
  NOTE_A4,8, NOTE_F5,8, NOTE_E5,8, NOTE_D5,8, NOTE_E5,8, NOTE_F5,4,
  NOTE_E5,8, NOTE_D5,4, NOTE_C5,4, NOTE_F5,8, NOTE_E5,2, REST, 5,

  // ohhh ohhh ohhh
  NOTE_D5,2, NOTE_C5,2, NOTE_D5,2, REST, 4,

  // caballo homosexual de las montanas
  NOTE_A4,8, NOTE_F5,8, NOTE_E5,8, NOTE_D5,8, NOTE_E5,8, NOTE_F5,4,
  NOTE_E5,8, NOTE_D5,4, NOTE_C5,4, NOTE_F5,8, NOTE_E5,2, REST, 4,

  // ningun animal se salva
  NOTE_F5,4, NOTE_E5,8, NOTE_F5,4, NOTE_E5,8, NOTE_D5,4, NOTE_C5,8, NOTE_D5,3, REST, 4,

  // ending
  NOTE_F4,8, NOTE_F4,8, NOTE_F4,8,  NOTE_F5,8, NOTE_F5,4, NOTE_E5,4,
  NOTE_E4,8, NOTE_E4,8, NOTE_E4,8,  NOTE_F5,8, NOTE_F5,4, NOTE_E5,4,
  NOTE_D5,2, NOTE_D5,3, NOTE_D5,4, NOTE_D5,8, NOTE_C5,4, NOTE_D5,2,
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void loop() {
  // no need to repeat the melody.
}