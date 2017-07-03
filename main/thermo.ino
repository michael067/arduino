#define THERM_PIN 5
#define PAD       10000      // Pad Resistance

void initTherm() {
  pinMode(THERM_PIN, INPUT);
}

int getADCThermValue() {
  return analogRead(THERM_PIN);
}

// see : https://github.com/objenious-community/Kit-Dev/blob/master/Arduino%20Files/Objenious_Temperature/Objenious_Temperature.ino
float parseThermistor(int RawADC) {
  long Resistance;  
  float Temp;  // Dual-Purpose variable to save space.

  Resistance=PAD*((1024.0 / RawADC) - 1); 
  Temp = log(Resistance); // Saving the Log(resistance) so we can use it later
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;  // Convert Kelvin to Celsius                      

  return Temp;                                      // Return the Temperature
}
