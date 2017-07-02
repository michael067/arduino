#include <SoftwareSerial.h>

#define SERIAL_BAUDS 9600

#define SOFTWARE_SERIAL_RX_PIN 10
#define SOFTWARE_SERIAL_TX_PIN 11

SoftwareSerial softwareSerial =  SoftwareSerial(SOFTWARE_SERIAL_RX_PIN, SOFTWARE_SERIAL_TX_PIN);

void initSerial() {
  if (ENABLE_SERIAL) {
    Serial.begin(SERIAL_BAUDS);  
    Serial.println("ok");
  }
}

void initSoftwareSerial() {
  if (ENABLE_SOFTWARE_SERIAL) {
    turnGreenLedON();
    pinMode(SOFTWARE_SERIAL_RX_PIN, INPUT);
    pinMode(SOFTWARE_SERIAL_TX_PIN, OUTPUT);
    
    softwareSerial.begin(SERIAL_BAUDS);
    softwareSerial.println("ok");
    turnGreenLedOFF();
  }
}
void sendWdgIndex() {
  if (ENABLE_SERIAL) {
    Serial.println(wdgIndex);
  }
  if (ENABLE_SOFTWARE_SERIAL) {
    turnGreenLedON();
    softwareSerial.println(wdgIndex);
    turnGreenLedOFF();
  }
}

void sendOnSerial(byte* batteryLevelBytes, int arrayLength) {
  for (int i = 0; i < arrayLength; i++) {
    if (ENABLE_SERIAL) {    
      Serial.print(batteryLevelBytes[i], HEX);
      Serial.print("-");
    }
    if (ENABLE_SOFTWARE_SERIAL) {    
      softwareSerial.print(batteryLevelBytes[i], HEX);
      softwareSerial.print("-");
    }
  }
  
  if (ENABLE_SERIAL) {
    Serial.println("-");
  }
  if (ENABLE_SOFTWARE_SERIAL) {
    softwareSerial.println("-");
  }
}

void sendADCValues() {
  if (ENABLE_SEND_ADC_VALUES) {
    int vusb = getVUSB();
    int vbat = getVBAT();
    
    if (ENABLE_SERIAL) {
      Serial.print("## VUSB : ");
      Serial.print(vusb);
      Serial.print(" ## VBAT : ");
      Serial.println(vbat);
    }

    if (ENABLE_SOFTWARE_SERIAL) {
      softwareSerial.print("## VUSB : ");
      softwareSerial.print(vusb);
      softwareSerial.print(" ## VBAT : ");
      softwareSerial.println(vbat);
    }
  }
}

void sendObjeniousIndex(int index) {
  if (SEND_OBJENIOUS_INDEX) {
    if (ENABLE_SERIAL) {
      Serial.print("## Objenious index : ");
      Serial.println(index);
    }

    if (ENABLE_SOFTWARE_SERIAL) {
      softwareSerial.print("## Objenious index : ");
      softwareSerial.println(index);
    }
  }  
}

void sendObjeniousReset() {
  if (SEND_OBJENIOUS_INDEX) {
    if (ENABLE_SERIAL) {
      Serial.println("## Objenious reset...");
    }

    if (ENABLE_SOFTWARE_SERIAL) {
      softwareSerial.print("## Objenious index : ");
    }
  }  
}

