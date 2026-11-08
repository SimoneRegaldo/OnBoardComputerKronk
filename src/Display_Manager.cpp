#include "Display_Manager.h"

Arduino_ESP32RGBPanel *rgb_panel = new Arduino_ESP32RGBPanel(
    PIN_DE, PIN_VSYNC, PIN_HSYNC, PIN_PCLK,
    PIN_R0, PIN_R1, PIN_R2, PIN_R3, PIN_R4,
    PIN_G0, PIN_G1, PIN_G2, PIN_G3, PIN_G4, PIN_G5,
    PIN_B0, PIN_B1, PIN_B2, PIN_B3, PIN_B4,
    0 /* HSYNC_POLARITY */, 4 /* HSYNC_FRONT_PORCH */, 4 /* HSYNC_PULSE_WIDTH */, 8 /* HSYNC_BACK_PORCH */,
    0 /* VSYNC_POLARITY */, 4 /* VSYNC_FRONT_PORCH */, 4 /* VSYNC_PULSE_WIDTH */, 8 /* VSYNC_BACK_PORCH */,
    1 /* PCLK_ACTIVE_NEG */, 13000000 /* PCLK_FREQ */
);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    LCD_WIDTH, LCD_HEIGHT, rgb_panel, 0, true
);

void DisplayManager::begin() 
{
  // 初始化屏幕
  if (!gfx->begin()) {
      Serial.println("GFX Init Failed!");
      while (1);
  }
}

void DisplayManager::drawMainScreen() 
{
  
}

bool DisplayManager::checkTouch(int &touchX, int &touchY) 
{
  return false;
}

void DisplayManager::showScanningState(bool scanning) 
{
  
}

void DisplayManager::turnOnBackLight()
{
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
}