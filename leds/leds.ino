/*
  Blink LED
  - turn an LED on for one second, then off for one second, repeatedly.

  The AirBoard is a thumb-size, Arduino-compatible, wireless, low-power,
  ubiquitous computer designed to sketch Internet-of-Things, fast!
  Visit http://www.theairboard.cc
  Upload your first sketch in seconds from https://codebender.cc?referral_code=Ub56L825Qb
  Check README.txt and license.txt for more information.
  All text above must be included in any redistribution.
*/


#define GREEN   5               // GREEN dimmable LED
#define BLUE   6               // BLUE dimmable LED
#define RED      9               // RED dimmable LED

#define PAUSE_TIME 4
#define SECOND 1000

#define FULL_LIGHT 255
#define NO_LIGHT 0



// the setup routine runs once when you switch on the board:
void setup() {
  pinMode(GREEN, OUTPUT);       // initialize the digital pin as an output
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  //Serial.begin(9600);


  //Serial.println(value, DEC);

  analogWrite(GREEN, FULL_LIGHT);     // turn the LED on and adjust the LED brightness between 1 and 255
  analogWrite(BLUE, FULL_LIGHT);     // turn the LED on and adjust the LED brightness between 1 and 255
  analogWrite(RED, FULL_LIGHT);
  delay(SECOND);                 // wait for a second
  analogWrite(GREEN, NO_LIGHT);     // turn the LED on and adjust the LED brightness between 1 and 255
  analogWrite(BLUE, NO_LIGHT);     // turn the LED on and adjust the LED brightness between 1 and 255
  analogWrite(RED, NO_LIGHT);

}

// the loop routine runs over and over again forever:
void loop() {
  //sendSerial("Green");
  risePin(GREEN);
  //sendSerial("Blue");
  risePin(BLUE);
  //sendSerial("RED");
  risePin(RED);
}


