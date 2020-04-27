#include "nanoled.hpp"


void onBoardLedBlink() {

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

}

void setupOnBoardLed() {

  pinMode(LED_BUILTIN, OUTPUT);

}

