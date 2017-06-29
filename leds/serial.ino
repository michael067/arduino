
struct tata {
  int a;
  int b;
  
};

void sendSerial(String serialText) {
  Serial.println(serialText); 
}


void risePin(int pinNumber) {
  for (int i = 0; i <= 255; i++) {
    analogWrite(pinNumber, i);
    delay(PAUSE_TIME);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(pinNumber, i);
    delay(PAUSE_TIME);
  }
}
