#include "Display_Manager.h"

void DisplayManager::begin() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

void DisplayManager::drawMainScreen() {
  tft.fillScreen(TFT_BLACK);
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextDatum(TC_DATUM);
  tft.drawString("Monitor Batteria Camper", tft.width() / 2, 20, 2);

  tft.fillRoundRect(btnX, btnY, btnW, btnH, 10, TFT_BLUE);
  tft.drawRoundRect(btnX, btnY, btnW, btnH, 10, TFT_WHITE);
  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("AVVIA SCANSIONE", btnX + (btnW / 2), btnY + (btnH / 2), 2);
}

bool DisplayManager::isScanButtonPressed(int touchX, int touchY) {
  if (touchX > btnX && touchX < (btnX + btnW) &&
      touchY > btnY && touchY < (btnY + btnH)) {
    return true;
  }
  return false;
}

void DisplayManager::showScanningState(bool scanning) {
  if (scanning) {
    tft.fillRect(0, 190, tft.width(), 40, TFT_BLACK);
    tft.setTextDatum(TC_DATUM);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.drawString("Scansione in corso...", tft.width() / 2, 200, 2);
  } else {
    tft.fillRect(0, 190, tft.width(), 40, TFT_BLACK);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawString("Scansione completata!", tft.width() / 2, 200, 2);
  }
}