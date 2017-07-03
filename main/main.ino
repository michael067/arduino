// ---------------------------------------------------------------------
// Include
// ------------------------------------------------------------------
#include <TheAirBoard.h>
#include <ATIM_LoRa.h> //ATIM library for LoRaWAN connection

// ---------------------------------
// Debug flags
// ---------------------------------
// uncomment for debug
//#define DELAY_8S      4000
//#define WDG_COUNT     5
//#define ENABLE_SERIAL true
//#define ENABLE_SEND_ADC_VALUES true
//#define ENABLE_SOFTWARE_SERIAL true
//#define SEND_OBJENIOUS_INDEX true
//#define OBJENIOUS_MESSAGE_THRESHOLD 3


#ifndef DELAY_8S
#define DELAY_8S      8000
#endif

#define DELAY_1S      1000
#define BLINK_DELAY   64

#ifndef WDG_COUNT
#define WDG_COUNT     30
#endif

#define IDLE_DELAY    50
#define SENT_BYTES_LENGTH 5
#ifndef OBJENIOUS_MESSAGE_THRESHOLD
#define OBJENIOUS_MESSAGE_THRESHOLD 100
#endif

#ifndef ENABLE_SERIAL
#define ENABLE_SERIAL false
#else
#define ENABLE_OBJENIOUS false
#endif

#ifndef ENABLE_SOFTWARE_SERIAL
#define ENABLE_SOFTWARE_SERIAL false
#endif

#ifndef ENABLE_OBJENIOUS
#define ENABLE_OBJENIOUS true
#endif

#ifndef ENABLE_SEND_ADC_VALUES
#define ENABLE_SEND_ADC_VALUES false
#endif

#ifndef SEND_OBJENIOUS_INDEX
#define SEND_OBJENIOUS_INDEX false
#endif

TheAirBoard board;

volatile int wdgIndex;;
// Watchdog ISR
ISR(WDT_vect) {
  wdgIndex++;
}

int objeniousMessageCount = 0;

// ---------------------------------------------------------------------
// Config
// ---------------------------------------------------------------------
void setup()
{
  initLeds();
  initSerial();
  initSoftwareSerial();
  initTherm();
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
    checkObjeniousReset();
    turnLedsOn();
    byte data[SENT_BYTES_LENGTH];
    getBatteryData(data);
    getThermData(data);
    
    sendOnSerial(data, SENT_BYTES_LENGTH);
    sendOnObjenious(data);
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

void sendOnObjenious(byte data[]) {
  if (ENABLE_OBJENIOUS) {
    sendData(data, SENT_BYTES_LENGTH);
    sendObjeniousIndex(objeniousMessageCount);
    objeniousMessageCount++;
  }
}

void checkObjeniousReset() {
  if (ENABLE_OBJENIOUS && objeniousMessageCount == OBJENIOUS_MESSAGE_THRESHOLD) {
    turnBlueLedON();
    turnGreenLedON();
    sendObjeniousReset();
    rebootObjenious();
    board.setWatchdog(DELAY_1S);
    board.powerDown();   
    // sleeping...
    //reset counters
    wdgIndex--;
    objeniousMessageCount = 0;
        
    board.setWatchdog(DELAY_8S);    
    turnBlueLedOFF();
    turnGreenLedOFF();
  }
}




