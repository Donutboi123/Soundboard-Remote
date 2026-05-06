#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//RX and TX ports on Arduino
SoftwareSerial mp3Serial(10, 11);
DFRobotDFPlayerMini player;

const int BTN = 2;
bool last = HIGH;

void setup() {

  pinMode(BTN, INPUT_PULLUP);

  Serial.begin(96000);
  mp3Serial.begin(9600);

  while (!player.begin(mp3Serial)) {

    delay(500);
  }

  //Max 30
  player.volume(25);
}

void loop() {

  bool now = digitalRead(BTN);

  if (last == HIGH && now == LOW) {
    player.stop();
    player.play(1);
  }

  last = now;
}
