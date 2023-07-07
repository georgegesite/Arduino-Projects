#include <avr/pgmspace.h>
#include "TMRpcm.h" // Audio File Library

TMRpcm music;


const unsigned char soundData[] PROGMEM = {

};

void setup()
{
  music.speakerPin = 9; // Audio output pin from Arduino
  Serial.begin(9600);

  music.setVolume(5); // 0 to 7. Set volume level
  music.quality(1); // Set 1 for 2x oversampling Set 0 for normal 

}

void loop()
{
    // Play the music file stored in PROGMEM
  music.play(soundData, sizeof(soundData));
  
  // Wait for the music to finish playing
  while (music.isPlaying())
  {
    delay(4000);
  }
}
