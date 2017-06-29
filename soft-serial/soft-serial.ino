#include <SoftwareSerial.h> // More information at https://www.arduino.cc/en/Reference/SoftwareSerial



// We define the pins for the software Serial that will allows us to
// debug our code.
//SoftwareSerial mySerial(10, 11); // Pin 10 will work as RX and Pin 11 as TX


// ---------------------------------------------------------------------
// Define
// ---------------------------------------------------------------------
// The 3 colours LED on the Airboard is driven by 3 different digital pins:
// PIN 5 is Green colour, PIN 9 is Red colour, PIN 6 is Blue color
#define LED_OK 5 
#define LED_ERROR 9
#define LED_TX 6
#define BOUTON 1


volatile boolean stateChanged = false; // True each time you will press the button, False otherwise
volatile boolean debounceStarted = false;
volatile uint32_t lastIntTmstp = 0;
static uint32_t debounceTime = 50;

boolean loupiote = true;

void setup()
{ 
  Serial.begin(9600);

    pinMode(BOUTON, INPUT_PULLUP);
    attachInterrupt(BOUTON, push, CHANGE); //interrupt 1 is on Pin D3 of the Airboard


    pinMode(LED_ERROR, OUTPUT); // RED color
    pinMode(LED_TX, OUTPUT); // BLUE color   
    pinMode(LED_OK, OUTPUT); // GREEN color 
    // Then we ensure the LEDs are OFF
    digitalWrite(LED_ERROR, LOW);
    digitalWrite(LED_TX, LOW);
    digitalWrite(LED_OK, LOW);

    digitalWrite(LED_OK, LOW);
    digitalWrite(LED_ERROR, LOW);

}


// ---------------------------------------------------------------------
// How the code works:
// Each time you press the button an interrupt will call the push() function
// This function will turn TRUE the "state" boolean variable.
// Each time the "state" variable is TRUE, the micro will:
//      * Send a LoRaWAN message to objenious
//      * Blink the BLUE LED for 100milisecond
//      * Print on the SoftwareSerial the same information sent to objenious
//      * Increment the sent messages counter.
// The buf string is defined at the beginning of this code, you can find more information 
// on how to concatenate strings at https://www.arduino.cc/en/Tutorial/StringAdditionOperator
// ---------------------------------------------------------------------

void loop()
{

    if(debounceStarted)
    {
//      Serial.println("debounce");
      if(millis() - lastIntTmstp > debounceTime)
      {
//        Serial.println("debounce OK");
        debounceStarted = false;
        digitalWrite(LED_TX, loupiote);
        loupiote = !loupiote;
      } 
    }
//    else
//    {
//        Serial.println("NO debounce");
//        delay(100);
//    }      
//    
}


// ---------------------------------------------------------------------
// Each time you press the button this function executes
// ---------------------------------------------------------------------

void push()
{
  lastIntTmstp = millis();
  debounceStarted = true;
}


// ---------------------------------------------------------------------
// This function makes blink the LED
// ---------------------------------------------------------------------
//
//void Blink(byte PIN, int DELAY_MS) 
//{ 
//  digitalWrite(PIN,HIGH);
//  delay(DELAY_MS);
//  digitalWrite(PIN,LOW);
//}
