#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include <TFT_eSPI.h>

class DisplayManager {
  public:
    void begin();
    void drawMainScreen();
    void showScanningState(bool scanning);
    bool isScanButtonPressed(int touchX, int touchY);

  private:
    TFT_eSPI tft = TFT_eSPI();
    int btnX = 60, btnY = 120, btnW = 200, btnH = 60;
};

#endif