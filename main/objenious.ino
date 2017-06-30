#include <ATIM_LoRa.h> //ATIM library for LoRaWAN connection
#define LED_DELAY 500

//Instance of  the class Arm
Arm Objenious; // Needed to make work the LoRaWAN module

armError_t initObjenious() {
  return Objenious.Init(&Serial);
}

armError_t configObjenious() {
  Objenious.SetMode(ARM_MODE_LORAWAN);
  Objenious.LwEnableRxWindows(true);
  Objenious.LwEnableTxAdaptiveSpeed(true);
  Objenious.LwEnableDutyCycle(true);
  Objenious.LwEnableTxAdaptiveChannel(true);
  Objenious.LwEnableRx2Adaptive(true);
  Objenious.LwEnableOtaa(true);
  Objenious.LwSetPortField(0x0a);
  Objenious.SetLed(ARM_LED_ON_RF);

  return Objenious.UpdateConfig();
}

void initObjeniousWithLeds() {
  turnBlueLedON();
  armError_t err = initObjenious();
  turnBlueLedOFF();
  
  manageObjeniousLeds(err);

  if (err != ARM_ERR_NONE) {
    turnBlueLedON();
    armError_t err = initObjenious();
    turnBlueLedOFF();
    manageObjeniousLeds(err);
  }
}

void manageObjeniousLeds(armError_t err) {
  if (err != ARM_ERR_NONE) {
    turnRedLedON();
    delay(LED_DELAY);
    return;
  } else {
    turnGreenLedON();
    delay(LED_DELAY);
    turnGreenLedOFF();
  }
}

void sendData(byte bytes[], int arrayLength) {
  Objenious.Send(bytes, arrayLength);
}


