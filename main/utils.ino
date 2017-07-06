#define VOLT_1_INDEX  0
#define VOLT_2_INDEX  1
#define BATTERY_STATS_INDEX 2
#define THERM_DATA_1  3
#define THERM_DATA_2  4
#define INTERNAL_THERM_DATA_1  5
#define INTERNAL_THERM_DATA_2  6

void floatToByte(float source, byte* returnBytes) {
  int intVolt = int(source * 100);  
  returnBytes[VOLT_1_INDEX] = byte(intVolt >> 8);
  returnBytes[VOLT_2_INDEX] = byte(intVolt);
}

void getBatteryData(byte* batteryLevelBytes) {
  float batLevel = batteryLevel();    
  floatToByte(batLevel, batteryLevelBytes);
  batteryLevelBytes[BATTERY_STATS_INDEX] = (isCharged()) ? 0x40 : 0x00;
  batteryLevelBytes[BATTERY_STATS_INDEX] += (usbPlugged()) ? 0x10 : 0x00;
  batteryLevelBytes[BATTERY_STATS_INDEX] += (isBatteryLow()) ? 0x01 : 0x00; 
}

void getThermData(byte* batteryLevelBytes) {
  int therm = parseThermistor(getADCThermValue()) * 100;    
  batteryLevelBytes[THERM_DATA_1] = byte(therm >> 8);
  batteryLevelBytes[THERM_DATA_2] = byte(therm); 
}

void setupInternalTemp(byte* batteryLevelBytes, double internalTemp) {
  int therm = internalTemp * 100;
  batteryLevelBytes[INTERNAL_THERM_DATA_1] = byte(therm >> 8);
  batteryLevelBytes[INTERNAL_THERM_DATA_2] = byte(therm); 
}
