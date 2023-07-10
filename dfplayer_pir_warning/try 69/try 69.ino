#include <PCM.h>

const unsigned char sample[] PROGMEM = {
  // Your audio sample data goes here
 
};

#define SENSORPIN 9
#define LED 12

bool isPlaying = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(SENSORPIN, INPUT);
  pinMode(LED, OUTPUT);
  startPlayback(sample, sizeof(sample));
}

void loop() {
  // put your main code here, to run repeatedly:
  int pirSensor = digitalRead(SENSORPIN);
  if (pirSensor == HIGH) {
    // PIR sensor is high, play music if not already playing
      digitalWrite(LED, HIGH);
    startPlayback(sample, sizeof(sample));
    }
   else {
    // PIR sensor is low, stop music if it's playing
      isPlaying = false;
      digitalWrite(LED, LOW);
    }
  }

