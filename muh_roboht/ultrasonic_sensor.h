#include "Arduino.h"

#define TrigPin 4
#define EchoPin 7

Timer timer;
int sensorTick = 100;
int timerEventId = -1;

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long getDistance()
{
  int duration;
  long distance;
  
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(TrigPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);
  distance = microsecondsToCentimeters(duration);

  return distance;
}

void checkDistance()
{
   long distance = getDistance();
   if(distance < 10)
   {
     isMovingAllowed = 0;
     timer.stop(timerEventId);
     timerEventId = -1;
   }
}

void setupUltrasonicSensor()
{
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  
  
}

void loopUltrasonicSensor()
{
  timer.update();
  
  if(isMoving == 1 && timerEventId == -1)
  {
    // start checking distance
     timerEventId = timer.every(sensorTick, checkDistance);
  }
}

onSerialUltrasonic(String input)
{
	if (input == "getDistanceFront")
	{
		trace("Distance at front: " + (String)getDistance() + "cm");
	}
}

