# Overview

This project works in conjunction with an Arduino board to operate a simple 'keyboard' setup, which consists of four buttons. Each button, when pressed, will play a specific tone and illuminate its corresponding LED light on the board. 

A fifth button provides replay functionality. When pressed, the board will replay the notes that have been played previously by the user (length of notes/pauses accounted for) and illuminate the appropriate LED's in conjunction with each note.

## Explanation

The board/software works by checking each of four digital input pins on a loop for a HIGH digitalRead(), which will occur when the corresponding button is actuated. If a pin has a HIGH input, the program will start a timer which will continue until the pin no longer has a HIGH voltage reading (i.e. until the user releases the button). After the button is released, a 'note' counter will be incremented and the note index and duration will be stored in two separate integer arrays. 

The program also checks a fifth input pin connected to a 'replay' button. If this button is actuated, each of the notes that the user entered will be replayed using the tone() function (or delay() function, in the case of pauses).

Due to the limitations of the Arduino hardware, the integer arrays used to store notes (including pauses) and their duration only have 100 indices. Therefore, the fundamental limitation on the number of notes that can be stored/replayed is 50 (50 notes, 50 pauses).

## Operation

This project was designed using the open-source Arduino IDE, and can be loaded onto any Arduino board with sufficient Input/Output pins. Once loaded, the program will begin execution immediately. 

NOTE: The time between when the program begins running and the first note is pressed will be recorded as a pause. E.g. if the user waits 10 seconds before playing a note, pressing the replay button will result in a 10 second pause prior to sounding the user-entered notes. 

## Credits

This project is an adaptation of the project provided on the Arduino.cc website; the original project upon which this code/setup is based can be found at the following URL:

_https://www.arduino.cc/en/Tutorial/ToneKeyboard_

Circuit diagram(s) were created using the 'Scheme-It' tool at:
_https://www.digikey.com/schemeit_

### Additional Information

__Adapted Code Written by Derek Avery__ 

Video Demonstration: _https://youtu.be/cu243N4TrFg_
