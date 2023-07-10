#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#define SENSORPIN 9
#define PAUSETIME 10000
#define RED_LED 4
#define GREEN_LED 5

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(19200);
  pinMode(SENSORPIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.println();
  Serial.println(F("Initializing DFPlayer..."));
  delay(1000);
  //Use softwareSerial to communicate with MP3
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    digitalWrite(RED_LED, HIGH);   
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));

    while (true)
      ;
  }
  Serial.println(F("DFPlayer Mini online."));
  digitalWrite(GREEN_LED, HIGH);  
  //Set volume value (From 0 to 30)
  myDFPlayer.volume(30);
}


void loop() {
  int pirSensor = digitalRead(SENSORPIN);
  if (pirSensor == HIGH) {
    Serial.println("Sensor Activated");
    myDFPlayer.play(1);
  }
}

