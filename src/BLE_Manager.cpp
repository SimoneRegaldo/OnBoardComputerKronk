#include "BleManager.h"

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      if (advertisedDevice.haveName()) {
        Serial.printf("Trovato BLE: %s | MAC: %s \n", 
                      advertisedDevice.getName().c_str(), 
                      advertisedDevice.getAddress().toString().c_str());
      }
    }
};

void BleManager::begin() {
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);
  Serial.println("BleManager inizializzato.");
}

void BleManager::startScan() {
  Serial.println("Avvio scansione BLE...");
  BLEScanResults* foundDevices = pBLEScan->start(scanTime, false);
  Serial.printf("Scansione completata. Trovati %d dispositivi.\n", foundDevices->getCount());
  pBLEScan->clearResults();
}