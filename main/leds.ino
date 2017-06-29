#define LED_GREEN 5
#define LED_RED 9
#define LED_BLUE 6

void initLeds() {
  pinMode(LED_GREEN, OUTPUT); // GREEN color
  pinMode(LED_BLUE, OUTPUT); // BLUE color
  pinMode(LED_RED, OUTPUT); // GREEN color
}

void turnLedsOff() {
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
}

void turnLedsOn() {
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_RED, HIGH);
}

void turnBlueLedON() {
  digitalWrite(LED_BLUE, HIGH);
}

void turnGreenLedON() {
  digitalWrite(LED_GREEN, HIGH);
}
void turnRedLedON() {
  digitalWrite(LED_RED, HIGH);
}

void turnBlueLedOFF() {
  digitalWrite(LED_BLUE, LOW);
}

void turnGreenLedOFF() {
  digitalWrite(LED_GREEN, LOW);
}
void turnRedLedOFF() {
  digitalWrite(LED_RED, LOW);
}

