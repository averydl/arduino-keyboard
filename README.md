## Overview

This project works in conjunction with an Arduino board to operate a simple 'keyboard' setup, which consists of four buttons. Each button, when pressed, will play a specific tone and illuminate its corresponding LED light on the board. 

A fifth button provides replay functionality. When pressed, the board will replay the notes that have been played previously by the user (length of notes/pauses accounted for) and illuminate the appropriate LED's in conjunction with each note.

## Operation

This project was designed using the open-source Arduino IDE, and can be loaded onto any Arduino board with sufficient Input/Output pins. Once loaded, the program will begin execution immediately. 

NOTE: The time between when the program begins running and the first note is pressed will be recorded as a pause. E.g. if the user waits 10 seconds before playing a note, pressing the replay button will result in a 10 second pause prior to sounding the user-entered notes. 

## Credits

This project is an adaptation of the project provided on the Arduino.cc website; the original project upon which this code/setup is based can be found at the following URL:

_https://www.arduino.cc/en/Tutorial/ToneKeyboard_

Circuit diagram(s) were created using the 'Scheme-It' tool at __https://www.digikey.com/schemeit__

Revised code written by Derek Avery 
