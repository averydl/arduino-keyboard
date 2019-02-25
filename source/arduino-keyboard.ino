#include "pitches.h"

/*  
 *   This code is written to operate an arduino UNO  
 *   board, which operates as a 'keyboard', playing tones
 *   via a connected buzzer/illuminating LED's in response to 
 *   button-pushes, then plays back the user-entered sequence of 
 *   notes (including pauses/note lengths) upon pressing a 'replay'
 *   button.
 *   
 *   This code has been adapted from the arduino project detailed
 *   at the following URL:
 *   
 *   https://www.arduino.cc/en/Tutorial/toneKeyboard
 *   
 *   Updated code by Derek Avery
 *   2019/02/25
 */
int songNotes[100]; // int array to hold notes played by user
long songLengths[100]; // int array to hold duration of notes played by user
int numNotes; // number of notes currently being stored

long noteStart; // start time of note
long pauseStart; // start time of pause

// notes to play, corresponding to the 4 buttons used
int notes[] = {
  NOTE_C3, NOTE_G3, NOTE_C4, NOTE_G4
};

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(13, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  songNotes[0] = -1;
  pauseStart = millis();
  numNotes = 1;
}

/* 
 *  Plays a musical note and illuminates the 
 *  corresponding LED for the specified duration. 
 *  If no key was pressed, pause without sound.
 */
void playNote(int note, int duration) {
  if(note != -1) {
    digitalWrite(note+8, HIGH);
    tone(6, notes[note], duration);
    delay(duration);
    digitalWrite(note+8, LOW);
  } else {
    delay(duration);
  }
}

void loop() {
  for (int input = 0; input < 4; input++) {
    // read input from current digital input 
    int curInput = digitalRead(input+2);

    // if the current input reads high (i.e. button is pressed) 
    if (curInput == HIGH) {
      
      // store the duration of the previous pause
      long curTime = millis(); 
      songLengths[numNotes] = curTime-pauseStart;
      songNotes[numNotes] = -1;
      numNotes++;

      // play the note/illuminate its corresponding LED
      noteStart = millis(); 
      digitalWrite(input+8, HIGH);
       
      // play the note while the button is still being pushed
      while(curInput == HIGH) {
        tone(6, notes[input], 10);
        curInput = digitalRead(input+2);
      }
      
      // store the note and its duration; re-start pause timer and turn off LED
      curTime = millis();
      songLengths[numNotes] = curTime-noteStart;
      pauseStart = curTime;
      songNotes[numNotes] = input;
      numNotes++;
      
      digitalWrite(input+8, LOW);
    } 

  }

//  // if 'reset' button is actuated, reset numNotes to 1
//  if(analogRead(0) > threshold) {
//    numNotes = 1;
//    pauseStart = millis();
//  }

  // if 'replay' button is actuated, play stored notes
  if(digitalRead(13) == HIGH) {
    for(int i = 0; i < numNotes; i++) {
      playNote(songNotes[i], songLengths[i]);
    }
  }
}
