#include "Arduino.h"
#include "BLE_Manager.h"
#include "Display_Manager.h"

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