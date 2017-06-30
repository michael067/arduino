// ---------------------------------------------------------------------
// Include
// ------------------------------------------------------------------
#include <TheAirBoard.h>
#include <ATIM_LoRa.h> //ATIM library for LoRaWAN connection

#define DELAY_8S 8000
#define DELAY_1S 1000
#define BLINK_DELAY 64
#define WDG_COUNT 30
#define IDLE_DELAY 50
#define SENT_BYTES_LENGTH 5

#define ENABLE_SERIAL false
#define ENABLE_SOFTWARE_SERIAL false
#define ENABLE_OBJENIOUS true
#define ENABLE_SEND_ADC_VALUES false

TheAirBoard board;

volatile int wdgIndex;;
// Watchdog ISR
ISR(WDT_vect) {
  wdgIndex++;
}

// ---------------------------------------------------------------------
// Config
// ---------------------------------------------------------------------
void setup()
{
  initLeds();
  initSerial();
  initSoftwareSerial();
  if (ENABLE_OBJENIOUS) {
    initObjeniousWithLeds();
  }
}

// ---------------------------------------------------------------------
// Run
// ---------------------------------------------------------------------

void loop()
{
  if (wdgIndex == WDG_COUNT) {
    turnLedsOn();
    byte batteryLevelBytes[SENT_BYTES_LENGTH];
    getBatteryData(batteryLevelBytes);
        
    sendOnSerial(batteryLevelBytes, SENT_BYTES_LENGTH);
    sendOnObjenious(batteryLevelBytes);
    sendADCValues();
    sleepAfterSend();
    
  } else {
    idleBlink();
  }
  sendWdgIndex();  
}


void sleepAfterSend() {
  board.setWatchdog(DELAY_1S);
  board.powerDown();
  turnLedsOff();
  board.setWatchdog(DELAY_8S);
  wdgIndex = 0;
  board.powerDown();
}

void idleBlink() {
  turnBlueLedON();
  board.setWatchdog(BLINK_DELAY);
  board.powerDown();  
  turnBlueLedOFF();
  wdgIndex--;
  board.setWatchdog(DELAY_8S);
  board.powerDown();
}

void sendOnObjenious(byte batteryLevelBytes[]) {
  if (ENABLE_OBJENIOUS) {
    sendData(batteryLevelBytes, SENT_BYTES_LENGTH);
  }
}





