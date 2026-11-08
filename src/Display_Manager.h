#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include <TAMC_GT911.h>

class DisplayManager {
  public:
    void begin();
    void drawMainScreen();
    void showScanningState(bool scanning);
    bool checkTouch(int &touchX, int &touchY);

  private:
    int btnX = 60, btnY = 120, btnW = 200, btnH = 60;
};

#endif