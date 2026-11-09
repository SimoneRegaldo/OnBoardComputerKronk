# 1 "/var/folders/xm/mnt5hf014lz6c58lxpj_c2s00000gn/T/tmp3oy91t9i"
#include <Arduino.h>
# 1 "/Users/dani/Documents/PlatformIO/Projects/OnBoardComputerKronnk/src/main.ino"
#include "Arduino.h"
#include "BLE_Manager.h"
#include "Display_Manager.h"

BleManager bleManager;
DisplayManager displayManager;
void setup();
void loop();
#line 8 "/Users/dani/Documents/PlatformIO/Projects/OnBoardComputerKronnk/src/main.ino"
void setup() {
  Serial.begin(115200);
  delay(1000);

  displayManager.begin();
  displayManager.drawMainScreen();


}

void loop() {
  delay(50);
}