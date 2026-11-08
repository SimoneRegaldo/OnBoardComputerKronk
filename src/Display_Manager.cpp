#include "Display_Manager.h"

// Definizione dei colori in formato RGB565 per Arduino_GFX
#define BLACK 0x0000
#define WHITE 0xFFFF
#define BLUE  0x001F
#define YELLOW 0xFFE0
#define GREEN 0x07E0

// Configurazione Display (Driver ST7789 via SPI)
Arduino_DataBus *bus = new Arduino_ESP32SPI(42 /* DC */, 45 /* CS */, 41 /* SCK */, 48 /* MOSI */, 39 /* MISO */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 40 /* RST */, 0 /* rotation */, true /* IPS */);

// Configurazione Touch Capacitivo GT911 (I2C) - Passiamo pin e risoluzione (320x240)
#define TOUCH_SDA 8
#define TOUCH_SCL 9
#define TOUCH_INT 4
#define TOUCH_RST 3

TAMC_GT911 ts = TAMC_GT911(TOUCH_SDA, TOUCH_SCL, TOUCH_INT, TOUCH_RST, 320, 240);

void DisplayManager::begin() {
  gfx->begin();
  gfx->fillScreen(BLACK);

  // Inizializzazione Touch Capacitivo
  ts.begin();
  ts.setRotation(ROTATION_LEFT); // Orientamento coerente con lo schermo
}

void DisplayManager::drawMainScreen() {
  gfx->fillScreen(BLACK);
  
  // Titolo
  gfx->setTextSize(2);
  gfx->setTextColor(WHITE);
  gfx->setCursor(30, 20);
  gfx->print("Monitor Batteria Camper");

  // Pulsante SCANSIONE
  gfx->fillRect(btnX, btnY, btnW, btnH, BLUE);
  
  gfx->setTextSize(2);
  gfx->setTextColor(WHITE);
  gfx->setCursor(btnX + 25, btnY + 20);
  gfx->print("SCANSIONE");
}

bool DisplayManager::checkTouch(int &touchX, int &touchY) {
  ts.read();
  if (ts.isTouched) {
    touchX = ts.points[0].x;
    touchY = ts.points[0].y;
    
    // Verifica se il tocco è nell'area del pulsante
    if (touchX > btnX && touchX < (btnX + btnW) &&
        touchY > btnY && touchY < (btnY + btnH)) {
      return true;
    }
  }
  return false;
}

void DisplayManager::showScanningState(bool scanning) {
  if (scanning) {
    gfx->fillRect(0, 200, 320, 40, BLACK);
    gfx->setCursor(50, 200);
    gfx->setTextSize(2);
    gfx->setTextColor(YELLOW);
    gfx->print("Scansione in corso...");
  } else {
    gfx->fillRect(0, 200, 320, 40, BLACK);
    gfx->setCursor(50, 200);
    gfx->setTextSize(2);
    gfx->setTextColor(GREEN);
    gfx->print("Scansione completata!");
  }
}