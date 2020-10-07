/*This script was created by GR3Y
 * 
 * This script is for use with the XC4492 motor controller but can be easilly adapted to suit other H-Bridge motor controllers by changing the output for the motor contoller
 * 
 * THIS SCRIPT IS FOR THE ARDUINO UNO AND NOT THE ESP8266, I HAVE LINKED THE OTHER CODE ALSO ON MY GITHUB PAGE
 * 
 * I have the PDF for the XC4492 motor controller on my github page
 * -
 */

const int forward_pin = 2; //pins 2, 3, 4, 5 will be used for inputs
const int rearward_pin = 3;
const int left_pin = 4;
const int right_pin = 5;

int forward = 0;  //variables for the stat of the input:
int rearward = 0;
int left = 0;
int right = 0;

const int motorOUT_1 = 6; //PWM outputs for motor controller:
const int motorOUT_2 = 9;
const int motorOUT_3 = 10;
const int motorOUT_4 = 11;



void setup() {

  pinMode(forward_pin, INPUT);  //input coming from esp8266:
  pinMode(rearward_pin, INPUT);
  pinMode(left_pin, INPUT);
  pinMode(right_pin, INPUT);
  
  //-------------------------------------------------------------
  //CHANGE OUTPUTS FOR DIFFERENT H-BRIDGE MOTOR CONTROLLERS
  //-------------------------------------------------------------
  pinMode(motorOUT_1, OUTPUT); //outputs for the motor controller:
  pinMode(motorOUT_2, OUTPUT); //motorA = motorOUT_1 and motorOUT_2:
  pinMode(motorOUT_3, OUTPUT); //motorB = motorOUT_3 and motorOUT_4:
  pinMode(motorOUT_4, OUTPUT);
  //-------------------------------------------------------------
  //-------------------------------------------------------------

}

void loop() {
  //asign the current output from the esp8266 to the appropiate variable:
  forward = digitalRead(forward_pin);
  rearward = digitalRead(rearward_pin);
  left = digitalRead(left_pin);
  right = digitalRead(right_pin);

  //If the forward option is correct then set the pins to output the forward signal:
  if (forward == HIGH) {
    digitalWrite(motorOUT_1, HIGH);
    digitalWrite(motorOUT_2, LOW);
    digitalWrite(motorOUT_3, HIGH);
    digitalWrite(motorOUT_4, LOW);
  }

  //If the rearward option is correct then set the pins to output the rearward signal:
  if (rearward == HIGH) {
    digitalWrite(motorOUT_1, LOW);
    digitalWrite(motorOUT_2, HIGH);
    digitalWrite(motorOUT_3, LOW);
    digitalWrite(motorOUT_4, HIGH);
  }

  //If the left option is correct then set the pins to output the left signal:
  if (left == HIGH) {
    digitalWrite(motorOUT_1, HIGH);
    digitalWrite(motorOUT_2, LOW);
    digitalWrite(motorOUT_3, LOW);
    digitalWrite(motorOUT_4, HIGH);
    
  }

  //If the right option is correct then set the pins to output the right siganl:
  if (right == HIGH) {
    digitalWrite(motorOUT_1, LOW);
    digitalWrite(motorOUT_2, HIGH);
    digitalWrite(motorOUT_3, HIGH);
    digitalWrite(motorOUT_4, LOW);
  }
}
