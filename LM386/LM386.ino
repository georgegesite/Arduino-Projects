#include <avr/pgmspace.h>
#include "TMRpcm.h" // Audio File Library

TMRpcm music;

const int pirPin = 2; // PIR sensor input pin

const int soundLength = 5000; // Adjust this value based on the length of your sound file
const unsigned int sampleRate = 8000; // Adjust this value based on the sample rate of your sound file

const unsigned char soundData[] PROGMEM = {

};

void setup()
{
  music.speakerPin = 9; // Audio output pin from Arduino
  Serial.begin(9600);

  music.setVolume(5); // 0 to 7. Set volume level
  music.quality(1); // Set 1 for 2x oversampling Set 0 for normal

  pinMode(pirPin, INPUT); // PIR sensor pin as input
}

void loop()
{
  // Check if the PIR sensor detects motion
  if (digitalRead(pirPin) == HIGH)
  {
    Serial.println("Motion detected");
    delay(1000); // Delay to avoid multiple trigger events
    
    // Play the music file stored in PROGMEM
    music.play(soundData, soundLength);
    
    // Wait for the music to finish playing
    while (music.isPlaying())
    {
      delay(100);
    }
  }
}
