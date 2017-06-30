#define LOWBAT     3.1 // battery low voltage threshold in V
#define VF         1.2 // SML-P11VT forward voltage in V (under current adjusted)
#define USB_MIDDLE_COMP 500

boolean usbPlugged() {
  return analogRead(VUSB) > USB_MIDDLE_COMP ? true:false;
}

float batteryLevel() {
  return 3.3 * analogRead(VBAT) / 1024 + VF;
}

boolean isBatteryLow() {
  return batteryLevel() < LOWBAT;
}

void sendADCValues() {
  if ((ENABLE_SEND_ADC_VALUES) && (ENABLE_SERIAL)) {
    Serial.print("## VUSB : ");
    Serial.print(analogRead(VUSB));
    Serial.print(" ## VBAT : ");
    Serial.println(analogRead(VBAT));
  }
}

