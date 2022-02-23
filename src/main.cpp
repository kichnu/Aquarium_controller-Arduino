
#include <Arduino.h>
#include "../lib/navBoard/naviBoard.h"
#include "../lib/display/display.h"
#include "controlRelays.h"

void setup()
{
  initDisplay();
  showDecorators();
  Serial.begin(9600);
  setupPins();
  showMessage(actualMessageNum);
  showInfo(actualMessageNum);
}

void loop()
{
  readBoard();
}