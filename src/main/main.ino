/////////////////////////////////////////////////////////////////////////////////////////
// Author: Cian Mc Namara (18CMcNamara97@stn.ie)
// 
// File: main.ino
// Description: The primary file for the 2022 5th year Bird Box Project
//
// Date of Creation: 09/11/2022
// Date of Last Edit: 15/11/2022                                                    
/////////////////////////////////////////////////////////////////////////////////////////

// Input Pins on Odd Numbers
// Output Pins on Even Numbers

// | Constants
int debugAnalogPin = A1; // Setting a debug pin for testing
int ledPin = 12; // Setting an ledPin for output
int pirPin = A3; // Setting a PIR pin for input

int morse_time = 65; // Time in miliseconds for 1 morse-unit

int board_number = 1;

// | Variables
int loops = 0;
bool bird_inside = false;
float pir_status;

// | Setup
void setup() {
  Serial.begin(9600); // Opens the Serial Port at 9600bps
  pinMode(pirPin, INPUT); // Setting the PIR Pins mode to Input
}

// | Functions
int getSerialNumber() {
  return board_number;
}
void onPIRChange() {
  if (getPIRInfo() < pir_status) {
    bird_inside = !bird_inside;
    Serial.print(strcat("Bird Inside: ", char(bird_inside)));
  }
  pir_status = analogRead(pirPin);
}

int getPIRInfo() {
  return analogRead(pirPin);
}

int get_morse_time(char str) {
  if (str == '.') {
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 1);
      digitalWrite(ledPin, LOW);
    }
    else if (str == '-') {
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 3);
      digitalWrite(ledPin, LOW);
    }
    else if (str == ' ') {
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 7);
      digitalWrite(ledPin, LOW);
    }
        else if (str == '/') {
      digitalWrite(ledPin, HIGH);
      delay(morse_time * 7);
      digitalWrite(ledPin, LOW);
    }
}

void flash_led() {
  int i;
  char str[] = "-... .. .-. -.. / .. -. ... .. -.. ."; 

  for (i = 0; i < strlen(str); i++) {
    digitalWrite(ledPin, HIGH);
    delay(get_morse_time(str[i]));
    digitalWrite(ledPin, LOW);
  };
  delay(5000); // Wait 5 seconds between messages
}

// | Main Loop
void loop() {
  loops = loops + 1;
  Serial.println(strcat("Loop: ", char(loops)));
  Serial.println("Debug-Pin A1: " + analogRead(debugAnalogPin)); // Checking the debug pin for errors
  onPIRChange(); // Checks if PIR data changes, if so it logs bird inside as the opposite of what it currently is
  if (bird_inside == true){
    flash_led();
  };
}
