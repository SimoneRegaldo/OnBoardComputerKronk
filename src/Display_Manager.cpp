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

static lv_display_t * disp;
static uint8_t buf[LCD_WIDTH * LCD_HEIGHT / 10 * 2];

void DisplayManager::begin() 
{
  // 初始化屏幕
  if (!gfx->begin()) {
      Serial.println("GFX Init Failed!");
      while (1);
  }
  else
  {
    lv_init();

    disp = lv_display_create(LCD_WIDTH, LCD_HEIGHT);
    lv_display_set_flush_cb(disp, myDispFlush);
    lv_display_set_buffers(disp, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
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

void DisplayManager::myDispFlush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  uint16_t *color_p = (uint16_t *)px_map;
  
#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, color_p, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, color_p, w, h);
#endif

  lv_disp_flush_ready(disp);
}