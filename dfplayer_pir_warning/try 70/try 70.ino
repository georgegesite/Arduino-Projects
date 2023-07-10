#include "TMRpcm.h" // Audio File Library

TMRpcm music;

void setup() {
  music.speakerPin = 9; // Audio output pin from Arduino
  Serial.begin(9600);
  music.setVolume(5); // 0 to 7. Set volume level
  music.quality(1); // Set 1 for 2x oversampling. Set 0 for normal
}

void loop() {
  music.play("song.wav"); // Replace "song.wav" with the actual file name of your song
  
  while (music.isPlaying()) {
    // Wait for the song to finish playing
  }
  
  delay(2000); // Delay for 2 seconds before playing the song again
}
