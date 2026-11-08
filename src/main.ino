#include "BleManager.h"
#include "DisplayManager.h"

BleManager bleManager;
DisplayManager displayManager;

void setup() {
  Serial.begin(115200);
  delay(1000);

  displayManager.begin();
  displayManager.drawMainScreen();
  
  bleManager.begin();
}

void loop() {
  delay(50);
}