/////////////////////////////////////////////////////////////////////////////////////////
// Author: Cian Mc Namara (18CMcNamara97@stn.ie)
// 
// File: main.ino
// Description: The primary file for the 2022 5th year Bird Box Project
//
// Date of Creation: 09/11/2022
// Date of Last Edit: 09/11/2022                                                    
/////////////////////////////////////////////////////////////////////////////////////////

// Input Pins on Odd Numbers
// Output Pins on Even Numbers

// | Constants
int debugAnalogPin = A1; // Setting a debug pin for testing
int ledPin = 12; // Setting an ledPin for output
int pirPin = 9; // Setting a PIR pin for input

int morse_time = 65 // Time in miliseconds for 1 unit

// | Variables
bool bird_inside = false;

// | Setup
void setup() {
  Serial.begin(9600); // Opens the Serial Port at 9600bps
  pinMode(pirPin, INPUT) // Setting the PIR Pins mod to Input
}

// | Functions
static char[] flash_led() {
  char[] str = "-... .. .-. -.. / .. -. ... .. -.. .";
  int i;
  for (i = 0; i < strlen(str); i++){
    if (str[i] == '.'){
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 1)
      digitalWrite(ledPin, LOW)
    }
    else if (str[i] == '-'){
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 3)
      digitalWrite(ledPin, LOW)
    }
    else if (str[i] == ' '){
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 7)
      digitalWrite(ledPin, LOW)
    }
        else if (str[i] == '/'){
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 7)
      digitalWrite(ledPin, LOW)
    }
    delay(5000) // Wait 5 seconds between messages
  }
  return str
}

// | Main Loop
void loop() {
  Serial.print("Pin A0: " + analgRead(debugAnalogPin)); // Checking the debug pin for errors
  if (bird_inside == true){
    flash_led()
  }
}
