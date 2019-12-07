/*
 Unravel Preset Piano

 Press one of the first four buttons and the buzzer will play a note.
 From left to right the piano notes are G4, A4, A#4 and C5.
 The fifth button is coded for a melody. Which means that when you press
 it a song, which you can code, will play.

 Made by: ExeCuteLi
 Published On: May 25, 2018
 Link to project:
 https://create.arduino.cc/projecthub/executeli/unravel-preset-piano-easy-arduino-even-a-ghoul-can-make-it-17c472?ref=similar&ref_id=65462&offset=3

 ------------------------------------------------------------------------
 Piano Music Box

 For this project I have replaced the fifth button with the piano key C#4.
 A potentiometer was added to control three states.
 The first state allows for the buttons and buzzer to act as a piano.
 The second state allows for the buttons to act as a music box.
 Each button in the music box mode will play a song.
 The third state will play every song on a loop.

 Songs were coded by watching tutorials such as this https://www.youtube.com/watch?v=6_qY9_rTGlk, 
 writing down what each note was and for how long the note played for on a scae of 1 to 8, and 
 then entering those numbers into the code

 Updated by: Braedon Rix
 Date: December 6, 2019
*/

//Defining every individual note, #include "pitches.h" was broken
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define ACTIVATED LOW

//Define Arrays for each song and the duration of the notes
// notes in the melody
//Defining which note will play next in a song
//int melody[] = {      Removed
//Unravel
//This is from the original project
//NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
//NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
//NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 
//NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3,
//NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
//NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_A3, NOTE_F3, 
//NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
//NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_G3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 
//};

// note durations: 4 = quarter note, 8 = eighth note, etc.
//Define how long each tone will play for
//int noteDurations[] = {     Removed
//Unravel - Removed
//4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
//4.5, 2.25, 4.5, 2.25, 1.125, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 
//4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2, 
//4.5, 4.5, 4.5, 2.25, 4.5, 4.5,
//4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
//4.5, 2.25, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 3, 3, 4.5, 
//2.25, 4.5, 2.25, 4.5, 2.25, 
//4.5, 4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 
//} ;

//Never Gonna Give You Up
//By: Rick Astley (1987)
int neverGoinToNotes[] = {
  NOTE_CS4, NOTE_CS4, 0, NOTE_CS4, NOTE_CS4, 
  0, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_CS4, NOTE_DS4, NOTE_C4, 
  NOTE_AS3, NOTE_GS3, 0, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, 0, NOTE_GS3, NOTE_GS4, NOTE_GS3, NOTE_DS4, 0, 
  NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_CS4, NOTE_DS4, 
  0, NOTE_C4, NOTE_AS3, NOTE_C4, NOTE_AS3, NOTE_GS3, 0, 
  NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_GS3, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, 
  NOTE_DS4, 0, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_CS4, NOTE_DS4, 
  NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_GS3, NOTE_GS3, 0, 
  NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS4, 0, NOTE_DS4, NOTE_F4, 
  NOTE_DS4, 0, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_F4, 
  NOTE_F4, NOTE_DS4, NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_GS3, NOTE_DS4, 
  NOTE_DS4, NOTE_CS4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, 
  NOTE_AS3, NOTE_CS4, NOTE_DS4, NOTE_C4, NOTE_AS3, NOTE_GS3, NOTE_F3, 
  NOTE_DS4, NOTE_CS4, 0, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, 
  NOTE_F4, NOTE_F4, NOTE_DS4, NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_GS3, 
  NOTE_GS4, NOTE_C4, NOTE_CS4, NOTE_CS4, NOTE_AS3, NOTE_GS3, NOTE_AS3, 
  NOTE_C4, NOTE_GS3, NOTE_CS4, NOTE_DS4, NOTE_C4, NOTE_AS3, NOTE_GS3, 
  NOTE_F3, NOTE_DS4, NOTE_CS4, 
  
  
};

// note durations: 4 = quarter note, 8 = eighth note, etc.
//Define how long each tone will play for
int neverGoingToDuration[] = {
  7, 7, 6, 7, 7, 
  5, 6.5, 6.5, 6, 6, 6.5, 6, 
  7, 1, 6, 6, 6, 6.5, 2, 
  6.5, 6, 6, 5, 6.5, 2, 4, 
  6, 6, 6.5, 6, 6, 6, 6, 
  5, 6, 6, 6, 7, 2, 5, 
  6, 6, 6.5, 6, 6, 6.5, 2, 
  6, 6, 6, 6, 6, 6, 6.5, 
  4, 6, 2, 6, 6, 6, 6, 
  6, 6, 6, 6, 6, 4, 5, 
  6, 6, 6, 6, 6, 6, 6, 
  5, 4, 7, 6.5, 7, 7, 6, 
  6, 4, 7, 7, 6.5, 7, 6, 
  6, 6, 6.5, 6.5, 7, 6.5, 7, 
  7, 5, 6.5, 6.5, 6.5, 5, 6.5, 
  5, 2, 6, 7, 7, 6.5, 7, 7, 
  6, 6, 4, 7, 7, 6.5, 1, 
  5, 6, 5.5, 6.5, 6.5, 7, 7, 
  6.5, 7, 5, 6.5, 6, 6.5, 5, 
  6, 6, 4, 
  
};

//All Star
//By: Smash Mouth (1999)
int allStarNotes[] = {
  NOTE_FS4, NOTE_CS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_B4, 
  NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_CS5, NOTE_AS4, 
  NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, 0, NOTE_FS4, 
  NOTE_FS4, NOTE_CS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, 
  NOTE_B4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_CS5, 
  NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, 0, 
  NOTE_FS4, NOTE_DS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, 
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, 
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_AS4, NOTE_FS4, NOTE_AS4, 
  NOTE_AS4, NOTE_CS5, NOTE_B4, NOTE_AS4, NOTE_FS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, 
  NOTE_GS4, NOTE_AS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, NOTE_FS4, NOTE_FS4, 
  NOTE_FS4, 0, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_DS5, NOTE_AS4, NOTE_CS5, 
  NOTE_AS4, NOTE_DS5, NOTE_AS4, NOTE_CS5, NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_FS4, 
  NOTE_FS4, NOTE_GS4, NOTE_FS4, 0, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, 
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, 0, NOTE_FS4, NOTE_FS4, NOTE_AS4, 
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, 0, NOTE_AS4, 
  NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_FS4, 
  NOTE_FS4, NOTE_FS4, NOTE_AS4, NOTE_AS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_FS4, 
  NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_AS4, 0, 
  NOTE_AS4, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_DS5, NOTE_FS5, NOTE_GS5, NOTE_FS5, 
  NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_FS4, 
  NOTE_GS4, NOTE_AS4, NOTE_DS4,
  
};

// note durations: 4 = quarter note, 8 = eighth note, etc.
//Define how long each tone will play for
int allStarDuration[] = {
  4, 5, 5, 3, 5, 5, 5, 3, 
  5, 5, 5, 5, 3, 5, 5, 5, 
  3, 5, 5, 5, 4, 2, 4, 5, 
  5, 5, 5, 5, 5, 5, 5, 5, 
  3, 5, 5, 5, 5, 5, 5, 4, 
  5, 5, 4, 5, 5, 4, 3, 4, 
  4, 4, 3.5, 3.5, 5, 5, 5, 5,
  3.5, 3.5, 4, 3, 3.5, 5, 5, 3.5,
  5, 5, 5, 5, 3.5, 5, 4, 5,
  5, 3.5, 3.5, 5, 5, 3.5, 3.5, 4, 
  5, 3.5, 3.5, 3.5, 5, 5, 3.5, 3.5,
  3.5, 3.5, 5, 3.5, 5, 3.5, 5, 3.5, 
  5, 3.5, 5, 3.5, 3.5, 3.5, 3.5, 3.5, 
  5, 3.5, 2.5, 4.5, 5, 5, 5, 3.5, 
  5, 5, 3.5, 4, 4, 5, 5, 5, 
  5, 3.5, 5, 5, 3.5, 2.5, 2, 3.5,
  2.5, 5, 5, 3.5, 2.5, 5, 5, 3.5, 
  2.5, 3, 2, 3.5, 3, 5, 5, 3.5, 
  2.5, 5, 5, 3.5, 2.5, 3, 3, 5, 
  3, 3, 3, 3.5, 3.5, 2.5, 3.5, 3, 
  3.5, 3.5, 3.5, 3.5, 3.5, 3.5, 3.5, 3, 
  4, 3.5, 8, 
  
};

//Soviet Anthem - I needed to remove some space because I was encountering errors
//By: Russia (1938)
//int sovietNotes[] = {
//  NOTE_C5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, 
//  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, 
//  NOTE_C5, NOTE_D5, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, 
//  NOTE_D5, NOTE_B4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_A4, 
//  NOTE_G4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4,
//  
//};
//
//// note durations: 4 = quarter note, 8 = eighth note, etc.
////Define how long each tone will play for
//int sovietDuration[] = {
//  5, 5.5, 7, 4.5, 6.5, 6.5, 5, 5.5, 7, 5,
//  6.5, 6.5, 5, 6.5, 6.5, 5, 6.5, 6.5, 5, 6.5, 
//  6.5, 6.5, 7, 7, 7, 6, 6.5, 5, 6.5, 7, 
//  5, 6.5, 6.5, 5, 5.5, 7, 5, 6.5, 6.5, 5, 
//  5.5, 7, 5, 6.5, 6.5, 5.5, 7, 2, 
//  
//};

//Mii Channel Theme
//By: Nintedo (2008)
int miiChannelNotes[] = {
  NOTE_FS4, 0, NOTE_A4, NOTE_CS5, 0, NOTE_A4, 0, NOTE_FS4, NOTE_D4, 0, NOTE_D4, 0, NOTE_D4, 
  0, NOTE_CS4, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_CS5, 0, NOTE_A4, 0, NOTE_FS4, NOTE_E5, 0,
  NOTE_DS5, NOTE_D5, 0, NOTE_GS4, 0, NOTE_CS5, NOTE_FS4, 0, NOTE_CS5, 0, NOTE_GS4, 0, 
  NOTE_CS5, 0, NOTE_G4, NOTE_FS4, 0, NOTE_E4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 
  0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_B3, NOTE_B3, NOTE_A3,
  
};

// note durations: 4 = quarter note, 8 = eighth note, etc.
//Define how long each tone will play for
int miiChannelDuration[] = {
  6.5, 6, 6, 6.5, 6, 6, 6, 6.5, 7, 7, 7, 7, 7, 
  1, 6.5, 6, 6.5, 6, 6.5, 6, 6, 6, 6.5, 3, 7.5, 
  6.5, 6, 4, 6.5, 6, 6.5, 6.5, 6, 6.5, 6, 6.5, 6, 
  6.5, 6, 6, 6.5, 6, 6, 6, 7, 7, 7, 7, 7, 
  7, 1, 7, 7, 7, 7, 7, 7, 1, 5, 5, 1, 
  
};

//Africa
//By: Toto (1984)
int africaNotes[] = {
  NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, NOTE_CS4, NOTE_B3, NOTE_E4, 
  NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_FS5, NOTE_E5, 
  NOTE_CS4, NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, NOTE_CS4, NOTE_B3, NOTE_E4, 
  NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_FS5, NOTE_E5, 
  0, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_GS4, 
  NOTE_AS4, NOTE_B4, NOTE_DS4, NOTE_DS4, NOTE_E4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_E4, 
  NOTE_E4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_B3, NOTE_DS4, NOTE_CS4, NOTE_B3, 
  NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, NOTE_CS4, NOTE_B3, 
  NOTE_E4, 0, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_GS4, 
  NOTE_AS4, NOTE_B4, NOTE_DS4, NOTE_DS4, NOTE_E4, NOTE_FS4, NOTE_FS4, NOTE_E4, 
  NOTE_E4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_B3, NOTE_DS3, NOTE_CS4, NOTE_B3, 
  NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, 0, NOTE_CS4, NOTE_CS4, NOTE_B3, NOTE_E4, 
  
};

// note durations: 4 = quarter note, 8 = eighth note, etc.
//Define how long each tone will play for
int africaDuration[] = {
  5, 7, 7, 7, 7, 6, 6, 6, 
  7, 7, 7, 7, 7, 7, 7, 7, 7, 7 ,7, 7, 7, 7, 7, 7, 5, 
  5, 7, 7, 7, 7, 7, 6, 6, 6, 7, 
  7, 7, 7, 7, 7, 7, 7, 7, 
  7, 7, 7, 7, 7, 7, 7, 5, 
  6, 7, 7, 7, 3, 7, 5, 6, 
  7, 2, 7, 5, 6, 7, 6, 5, 
  6.5, 7, 4, 6, 6, 4, 7, 6, 
  6, 6, 7, 6, 7, 6, 7, 6, 6, 
  4, 5, 7, 7, 7, 4, 5, 6, 
  7, 2, 7, 5, 6, 6, 6, 7, 
  6, 6, 3, 6, 6, 3, 7, 6, 
  6, 6, 7, 6, 7, 6, 7, 6.5, 6, 4, 
  
};


//Define pins and variables
const int PIEZO = 11;
const int LED = 13;
//int buttonSong = 8; Removed functionality that plays a song on fifth button
const int BUTTON_CS = 8;  //Added a new fifth button to replace buttonSong
const int playlist = 0; //Used to switch between modes
const int BUTTON_C = 6;
const int BUTTON_AS = 4;
const int BUTTON_A = 3;
const int BUTTON_G = 2;
int value;


void setup()
{
  pinMode(LED, OUTPUT); //Used to test if buttons where working correctly
  digitalWrite(LED,LOW);
  
  pinMode(BUTTON_CS, INPUT);  //Added the pinMode and digitalWrite for the new button to replace buttonSong
  digitalWrite(BUTTON_CS,HIGH);
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C,HIGH);
  pinMode(BUTTON_AS, INPUT);
  digitalWrite(BUTTON_AS,HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A,HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G,HIGH);
  //pinMode (buttonSong, INPUT);  Removed
  //digitalWrite(buttonSong, HIGH); Removed
}


void loop()
{
 
  //value = analogRead(playlist);
  value = 3;

//Piano Mode
//Each button plays one tone
  if (value == 1)
  {
    while(digitalRead(BUTTON_CS) == ACTIVATED)
    {
      tone(PIEZO,NOTE_CS5);
      digitalWrite(LED,HIGH);
    }
  
    while(digitalRead(BUTTON_C) == ACTIVATED)
    {
      tone(PIEZO,NOTE_C5);
      digitalWrite(LED,HIGH);
    }
    
    while(digitalRead(BUTTON_AS) == ACTIVATED)
    {
      tone(PIEZO,NOTE_AS4);
      digitalWrite(LED,HIGH);
    }

    while(digitalRead(BUTTON_A) == ACTIVATED)
    {
      tone(PIEZO,NOTE_A4);
      digitalWrite(LED,HIGH);
    }
  
    while(digitalRead(BUTTON_G) == ACTIVATED)
    {
      tone(PIEZO,NOTE_G4);
      digitalWrite(LED,HIGH);
    }
    
//Removed
//  if(digitalRead(buttonSong) == ACTIVATED) {
//    for (int thisNote=0; thisNote <85; thisNote++) {
//      int noteDuration = 600 / noteDurations[thisNote];
//      tone(11, melody[thisNote], noteDuration);
//      int pauseBetweenNotes = noteDuration * 1.50;
//      delay(pauseBetweenNotes);
//      noTone(11);
//    }
//  }

  noTone(PIEZO);
  digitalWrite(LED,LOW); 
  }

//Music Box Mode
//Each button plays a song
  if (value == 2)
  {
    while(digitalRead(BUTTON_CS) == ACTIVATED)
    {
      //Africa
      for (int n = 0; n < 118; n++)
      {
        int noteDuration5 = 600 / africaDuration[n];
        tone(11, africaNotes[n], noteDuration5);
        int pauseBetweenNotes5 = noteDuration5 * 1.50;
        delay(pauseBetweenNotes5);
        noTone(11);
      }
    }

    while(digitalRead(BUTTON_C) == ACTIVATED)
    {
      //Mii Channel
      for (int as = 0; as < 61; as++)
      {
        int noteDuration4 = 600 / miiChannelDuration[as];
        tone(11, miiChannelNotes[as], noteDuration4);
        int pauseBetweenNotes4 = noteDuration4 * 1.50;
        delay(pauseBetweenNotes4);
        noTone(11);
      }
    }

    while(digitalRead(BUTTON_AS) == ACTIVATED)  //I had to remove a song for memory
    {
      tone(PIEZO,NOTE_AS4);
      digitalWrite(LED,HIGH);
    }

    while(digitalRead(BUTTON_A) == ACTIVATED)
    {
      //All Star
      for (int m = 0; m < 171; m++)
      {
        int noteDuration2 = 600 / allStarDuration[m];
        tone(11, allStarNotes[m], noteDuration2);
        int pauseBetweenNotes2 = noteDuration2 * 1.50;
        delay(pauseBetweenNotes2);
        noTone(11);
      }
    }

    while(digitalRead(BUTTON_G) == ACTIVATED)
    {
      //Never Gonna Give You Up
      for (int a = 0; a < 134; a++)
      {
        int noteDuration = 600 / neverGoingToDuration[a];
        tone(11, neverGoinToNotes[a], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.50;
        delay(pauseBetweenNotes);
        noTone(11);
      }
    }

    noTone(PIEZO);
    digitalWrite(LED,LOW); 
  }

//Playlist Mode
//Plays all songs in a loop
  while (value == 3)
  {
    for (int v = 0; v < 118; v++)  //Africa
    {
      int noteDuration5 = 600 / africaDuration[v];
      tone(11, africaNotes[v], noteDuration5);
      int pauseBetweenNotes5 = noteDuration5 * 1.50;
      delay(pauseBetweenNotes5);
      noTone(11);
    }

    delay(200);
    
    for (int w = 0; w < 61; w++)  //Mii Channel Theme
    {
      int noteDuration4 = 600 / miiChannelDuration[w];
      tone(11, miiChannelNotes[w], noteDuration4);
      int pauseBetweenNotes4 = noteDuration4 * 1.50;
      delay(pauseBetweenNotes4);
      noTone(11);
    }

    delay(200);
    
    for (int x = 0; x < 1; x++) //Soviet Anthem
    {
      //Removed a song from the loop to reduce amount of memory used
    }

    delay(200);
    
    for (int y = 0; y < 171; y++)  //All Star
    {
      int noteDuration2 = 600 / allStarDuration[y];
      tone(11, allStarNotes[y], noteDuration2);
      int pauseBetweenNotes2 = noteDuration2 * 1.50;
      delay(pauseBetweenNotes2);
      noTone(11);
    }

    delay(200);
    
    for (int z = 0; z < 134; z++)  //Never Going To Give You Up
    {
      int noteDuration = 600 / neverGoingToDuration[z];
      tone(11, neverGoinToNotes[z], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.50;
      delay(pauseBetweenNotes);
      noTone(11);
    }

    delay(200);
  }
}
