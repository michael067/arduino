#define VOLT_1_INDEX  0
#define VOLT_2_INDEX  1
#define BATTERY_STATS_INDEX 2
#define LOW_BAT_INDEX 3

void floatToByte(float source, byte* returnBytes) {
  int intVolt = int(source * 100);  
  returnBytes[VOLT_1_INDEX] = byte(intVolt >> 8);
  returnBytes[VOLT_2_INDEX] = byte(intVolt);
}

void getBatteryData(byte* batteryLevelBytes) {
  float batLevel = batteryLevel();    
  floatToByte(batLevel, batteryLevelBytes);
  batteryLevelBytes[BATTERY_STATS_INDEX] = (usbPlugged()) ? 0x10 : 0x00;
  batteryLevelBytes[BATTERY_STATS_INDEX] += (isBatteryLow()) ? 0x01 : 0x00; 
}


