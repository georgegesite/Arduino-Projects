#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h> // DFPlayer Mini Library

SoftwareSerial mySerial(10, 11); // RX, TX for DFPlayer Mini

DFPlayerMini_Fast mp3;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  
  mp3.begin(mySerial);
  mp3.volume(15); // Set volume level (0 to 30)

  // Play the music file from the DFPlayer Mini module
  mp3.play(1); // Replace "1" with the actual file number on the DFPlayer Mini

  // Wait for the music to finish playing
  delay(5000);
}

void loop()
{
  // Code in the loop function is not needed in this case
}
