#include <avr/pgmspace.h>
#include <TMRpcm.h>

#define PIR_PIN 4        // PIR sensor pin
#define SPEAKER_PIN 11   // TDA2030 board input pin

TMRpcm audio;             // Create an instance of the TMRpcm library


const unsigned char soundData[] PROGMEM = {

};


void setup() {
  pinMode(PIR_PIN, INPUT);             // Set PIR sensor pin as input
  pinMode(SPEAKER_PIN, OUTPUT);        // Set speaker pin as output
  audio.speakerPin = SPEAKER_PIN;      // Set TMRpcm library's speaker pin
  audio.setVolume(5);                  // Set volume (0 to 7, adjust as needed)
  
  Serial.begin(9600);                  // Initialize serial communication (optional)
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {   // If motion is detected
    Serial.println("Motion detected!"); // Print message (optional)
    
    // Play the custom sound
    if (!audio.isPlaying()) {           // Check if audio is not already playing
      audio.play(soundData, sizeof(soundData));
    }
  }
}
