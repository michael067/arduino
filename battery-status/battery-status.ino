/*
Battery indicator
- check battery voltage, USB voltage and charge status periodically
- blink red/green while charging
- solid green when charged or when discharging
- solid red when battery low

The AirBoard is a thumb-size, Arduino-compatible, wireless, low-power,
ubiquitous computer designed to sketch Internet-of-Things, fast!
Visit http://www.theairboard.cc
Upload your first sketch in seconds from https://codebender.cc?referral_code=Ub56L825Qb
Check README.txt and license.txt for more information.
All text above must be included in any redistribution.
*/

// Place /TheAirBoard folder in your Preferences>Sketchbook location /libraries folder.
// You may need to create the /libraries subfolder if it is your first library.
// Restart the Arduino IDE.
#include <TheAirBoard.h>

TheAirBoard board;


#define GREEN 5    // GREEN dimmable LED
#define BLUE  6    // BLUE dimmable LED
#define RED   9    // RED dimmable LED

volatile boolean f_wdt = true;

ISR(WDT_vect) {
    f_wdt = true;
}

// the setup routine runs once when you switch on the board:
void setup() {
   pinMode(GREEN, OUTPUT); // initialize the digital pin as an output
 pinMode(BLUE, OUTPUT);  // initialize the digital pin as an output
 pinMode(RED, OUTPUT);   // initialize the digital pin as an output
  Serial.begin(9600);                 // initialize serial communication at 9600 bits per second
  board.setWatchdog(8000);  
}

// the loop routine runs over and over again forever:
void loop() {
  
    if(f_wdt) {       // every 500 milliseconds
      digitalWrite(BLUE, HIGH);
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, HIGH);
      //Serial.println(millis()); // display battery level
      f_wdt = false;
      
    }
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    board.powerDown();
    
}
