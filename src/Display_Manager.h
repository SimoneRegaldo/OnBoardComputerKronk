#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino_GFX_Library.h>
#include <lvgl.h>

#define TFT_BL 2

#define LCD_WIDTH   800
#define LCD_HEIGHT  480

#define PIN_DE      40
#define PIN_VSYNC   41
#define PIN_HSYNC   39
#define PIN_PCLK    42
#define PIN_R0      45
#define PIN_R1      48
#define PIN_R2      47
#define PIN_R3      21
#define PIN_R4      14
#define PIN_G0      5
#define PIN_G1      6
#define PIN_G2      7
#define PIN_G3      15
#define PIN_G4      16
#define PIN_G5      4
#define PIN_B0      8
#define PIN_B1      3
#define PIN_B2      46
#define PIN_B3      9
#define PIN_B4      1

class DisplayManager {
  public:
    void begin();
    void drawMainScreen();
    void showScanningState(bool scanning);
    bool checkTouch(int &touchX, int &touchY);
    void turnOnBackLight();
    void myDispFlush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);

  private:
    int btnX = 60, btnY = 120, btnW = 200, btnH = 60;
};

#endif