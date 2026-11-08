#ifndef BLE_MANAGER_H
#define BLE_MANAGER_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

class BleManager {
  public:
    void begin();
    void startScan();

  private:
    BLEScan* pBLEScan;
    int scanTime = 4;
};

#endif