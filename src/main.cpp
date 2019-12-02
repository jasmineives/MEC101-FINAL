#include <Arduino.h>
#include <Servo.h>
#include <SPI.h>
#include <Pixy.h>
#include <Motor.h>

/*

Notes: when power is plugged into the motor correctly, the output shaft will
always turn away from the red wire, towards the red wire.

*/

/************************************************************************

  Config and Setup

***********************************************************************/
//const int driverName[3] = [enable, forward, backward]

const int leftDriverPin[3] = {7 , 22, 23};
const int rightDriverPin[3] = {6 , 24, 25};
const int sweeperPin[3] = {5 , 26, 27};

const int servoPin = 9;
const int leftTrig = 46;
const int leftEcho = 47;
const int rightTrig = 48;
const int rightEcho = 49;
const int tiltPin = 50;
const int powerPin = 53;
const int modePin = 52;

//class creation
Servo riserServo;

int powerState = 0;
int modeState = 0;
int tiltState = 0;

//format: Motor myMotor(enable, forwardPin, backwardPin)
Motor leftMotor(leftDriverPin[0], leftDriverPin[1], leftDriverPin[2]);
Motor rightMotor(rightDriverPin[0], rightDriverPin[1], rightDriverPin[3]);
Motor sweeper(sweeperPin[1], sweeperPin[2], sweeperPin[3]);


  //optimally, input is between -10, 10 each
  void diffDrive(int leftSpeed, int rightSpeed) {
    leftMotor.drive(leftSpeed);
    rightMotor.drive(rightSpeed);
    Serial.println(leftSpeed);
  }


/************************************************************************

SETUP AND LOOP

************************************************************************/
void setup() {
  
  Servo.attach(servoPin);
  
  pinMode(leftTrig, OUTPUT);
  pinMode(rightTrig, OUTPUT);
  pinMode(leftEcho, INPUT);
  pinMode(rightEcho, INPUT);
  

  Serial.begin(9600);
}



void loop() {
  rightServo.write(70);
  leftServo.write(70);
  diffDrive(10 ,10);

  delay(2000);
  leftServo.write(30);
  rightServo.write(100);
  diffDrive(-5,-5);
  delay(1000);
  // put your main code here, to run repeatedly:

  //leftMotor.drive(10);
  //analog.analogWrite()
}

/************************************************************************

FUNCTIONS AND RELATED CODE

************************************************************************/



/*

void forward(int speed){
  digitalWrite(motorOne_InputOne, HIGH);
  digitalWrite(motorOne_InputTwo, LOW);
  digitalWrite(motorTwo_InputOne, HIGH);
  digitalWrite(motorTwo_InputTwo, LOW);

  analogWrite (motorOne_Enable, speed);
  analogWrite (motorTwo_Enable, speed);
}

void reverse(int speed){
  digitalWrite(motorOne_InputOne, LOW);
  digitalWrite(motorOne_InputTwo, HIGH);
  digitalWrite(motorTwo_InputOne, LOW);
  digitalWrite(motorTwo_InputTwo, HIGH);

  analogWrite (motorOne_Enable, speed);
  analogWrite (motorTwo_Enable, speed);
}

void turnRight(int speed){
  digitalWrite(motorOne_InputOne, HIGH);
  digitalWrite(motorOne_InputTwo, LOW);
  digitalWrite(motorTwo_InputOne, LOW);
  digitalWrite(motorTwo_InputTwo, HIGH);

  analogWrite (motorOne_Enable, speed);
  analogWrite (motorTwo_Enable, speed);

  delay(moveTime);
}

void turnLeft(int speed){
  digitalWrite(motorOne_InputOne, LOW);
  digitalWrite(motorOne_InputTwo, HIGH);
  digitalWrite(motorTwo_InputOne, HIGH);
  digitalWrite(motorTwo_InputTwo, LOW);

  analogWrite (motorOne_Enable, speed);
  analogWrite (motorTwo_Enable, speed);

  delay(moveTime);
}

void accelerate(){
  for(int i = 100; i < 225; i++){
   analogWrite (motorOne_Enable, i);
   analogWrite (motorTwo_Enable, i);
  }
}

void decelerate(){
   for(int i = 225; i > 100; i--){
   analogWrite (motorOne_Enable, i);
   analogWrite (motorTwo_Enable, i);
  }
}
*/
