#define SERIAL_BAUDS 9600

void initSerial() {
  if (ENABLE_SERIAL) {
    Serial.begin(SERIAL_BAUDS);  
    Serial.println("ok");
  }
}

void sendWdgIndex() {
  if (ENABLE_SERIAL) {
    Serial.println(wdgIndex);
  }
}

void sendOnSerial(byte* batteryLevelBytes) {
  if (ENABLE_SERIAL) {
    for (int i = 0; i < 5; i++) {
      Serial.print(batteryLevelBytes[i], DEC);
      Serial.print("-");
    }
    Serial.println("-");
  }
}
