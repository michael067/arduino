#define LOWBAT     3.1 // battery low voltage threshold in V
#define VF         1.2 // SML-P11VT forward voltage in V (under current adjusted)

boolean usbPlugged() {
  return analogRead(VUSB) ? true:false;
}

float batteryLevel() {
  return 3.3 * analogRead(VBAT) / 1024 + VF;
}

boolean isBatteryLow() {
  return batteryLevel() < LOWBAT;
}

