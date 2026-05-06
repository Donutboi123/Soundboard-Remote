#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//RX and TX ports on Arduino
SoftwareSerial mp3Serial(10, 11);
DFRobotDFPlayerMini player;

//Pins used for buttons
const int buttonPins[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

//Previous button states
bool last[8];

void setup() {

  for (int i = 0; i < 8; i++) {

    pinMode(buttonPins[i], INPUT_PULLUP);
    last[i] = HIGH;
  }

  Serial.begin(96000);
  mp3Serial.begin(9600);

  while (!player.begin(mp3Serial)) {

    delay(500);
  }

  //Max 30
  player.volume(25);
}

void loop() {

  for (int i = 0; i < 8; i++) {

    bool now = digitalRead(buttonPins[i]);


    //Detect button press
    if (last[i] == HIGH && now == LOW) {
      player.stop();
      player.play(i + 1);

      delay(200);
    }

    last[i] = now;
  }
}
