void floatToByte(float source, byte* returnBytes) {
  returnBytes[0] = byte(source);
  returnBytes[1] = byte(source * 10 - returnBytes[0] * 10);
  returnBytes[2] = byte(source * 100 - returnBytes[0] * 100 - returnBytes[1] * 10);
}

void getBatteryData(byte* batteryLevelBytes) {
  float batLevel = batteryLevel();    
  floatToByte(batLevel, batteryLevelBytes);
  batteryLevelBytes[3] = usbPlugged();
  batteryLevelBytes[4] = isBatteryLow();
}


