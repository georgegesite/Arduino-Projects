#include "SD.h" //SD card library
#include "TMRpcm.h" //Audio File Library
#include "SPI.h" //SPI library for SD card
#define SD_ChipSelectPin 10

TMRpcm music;
int button1, button2;
int song_number=0;
boolean play_pause;

void setup()
{
music.speakerPin = 9; //Audio output pin from Arduino
Serial.begin(9600);
if (!SD.begin(10))
{
Serial.println("SD fail");
return;
}

pinMode(2, INPUT_PULLUP); //Pull up for change track switch
pinMode(3, INPUT_PULLUP); //Pull up for play/pause switch
pinMode(3, INPUT_PULLUP); //Pull up for fast forward
music.setVolume(5); // 0 to 7. Set volume level
music.quality(1); // Set 1 for 2x oversampling Set 0 for normal
}

void loop()
{
button1 = digitalRead(2);
button2 = digitalRead(3);
Serial.println(button1);
Serial.println(button2);

if (button2== LOW) //Button 2 Pressed
{
Serial.println("PLAY / PAUSE");
music.pause();
}

if (button1 == LOW) //Button 1 Pressed
{
song_number++;
if (song_number==7)
{song_number=1;}
Serial.println("KEY PRESSED");
Serial.print("song_number=");
Serial.println(song_number);
if (song_number ==1)
{music.play("1.wav",25);} //Play song 1 from 10th second
if (song_number ==2)
{music.play("2.wav",20);} //Play song 2 from 33rd second
if (song_number ==3)
{music.play("3.wav",15);} //Play song 3 from start
if (song_number ==4)
{music.play("4.wav",71);} //Play song 4 from 25th second
if (song_number ==5)
{music.play("5.wav");} //Play song 5 from start
if (song_number ==6)
{music.play("6.wav",58);} //Play song 6 from start }
}
delay(200);
}