#include "Arduino.h"

int isMoving = 0;
int areMotorsStopped = 1;



void setupMotors()
{
 //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin 
}

void moveForward()
{
  areMotorsStopped = 0;
  isMoving = 1;

  // motor a fwd half speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at half speed

  // motor b fwd half speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);   //Spins the motor on Channel B at half speed
  

  Event e = Event(EventType::MOTOR, EventType::MOTOR_FWD);
  evtMgr.trigger(e);
}

void brake()
{
  areMotorsStopped = 0;
  isMoving = 0;

  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
  digitalWrite(8, HIGH);  //Engage the Brake for Channel B
  
  Event e = Event(EventType::MOTOR, EventType::MOTOR_BRK);
  evtMgr.trigger(e);
}

void stopMotorOutputs()
{
  areMotorsStopped = 1;
  
  analogWrite(3, 0);
  analogWrite(11, 0);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(9, LOW);  //Disengage the Brake for Channel A
  digitalWrite(8, LOW);  //Disengage the Brake for Channel B
  
  Event e = Event(EventType::MOTOR, EventType::MOTOR_IDLE);
  evtMgr.trigger(e);
}

void loopMotors()
{
 if(isMovingAllowed == 1 && isMoving == 0)
  {
    moveForward();
  }
  else if(isMovingAllowed == 0 && isMoving == 1)
  {
    brake();
    delay(1000);
  }
  else if(isMovingAllowed == 0 && isMoving == 0 && areMotorsStopped == 0)
  {    
    stopMotorOutputs();
  } 
}


















void tutorialMethod()
{
  //Motor A forward @ full speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(13, LOW);  //Establishes backward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 123);    //Spins the motor on Channel B at half speed


  delay(3000);


  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
  digitalWrite(8, HIGH);  //Engage the Brake for Channel B


  delay(1000);


  //Motor A forward @ full speed
  digitalWrite(12, LOW);  //Establishes backward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 123);    //Spins the motor on Channel A at half speed

  //Motor B forward @ full speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed


  delay(3000);


  digitalWrite(8, HIGH);  //Engage the Brake for Channel A
  digitalWrite(9, HIGH);  //Engage the Brake for Channel B


  delay(1000);
}

