#include "UltrasonicSensorManager.h"
#include "Arduino.h"
#include "Event.h"
#include <Timer.h>
#include "EventType.h"
#include "Model.h"
#include "MotorController.h"
#include "SerialManager.h"

#define TrigPin 4
#define EchoPin 7

long UltrasonicSensorManager::microsecondsToCentimeters(long microseconds)
{
	// The speed of sound is 340 m/s or 29 microseconds per centimeter.
	// The ping travels out and back, so to find the distance of the
	// object we take half of the distance travelled.
	return microseconds / 29 / 2;

}

long UltrasonicSensorManager::getDistance()
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

void UltrasonicSensorManager::setup()
{
	evtMgr = Model::evtMgr;
	timer = new Timer();
	pinMode(TrigPin, OUTPUT);
	pinMode(EchoPin, INPUT);

	sensorTick = 100;
	timerEventId = -1;
}

void checkDistance()
{
	EventManager *evtMgr;
	evtMgr = Model::evtMgr;

	UltrasonicSensorManager *usMgr;
	usMgr = Model::usSensorManager;

	Timer *timer;
	timer = usMgr->timer;

	SerialManager *serial;
	serial = Model::serialManager;

	int timerEventId = usMgr->timerEventId;

	long distance = usMgr->getDistance();

	if (distance < 10)
	{
		timer->stop(timerEventId);
		timerEventId = -1;

		serial->trace("obj front " + (String)distance + "cm");

		Event e = Event(EventType::SENSOR, EventType::SENSOR_OBJECT_CLOSE_IN_FRONT);
		evtMgr->trigger(e);
	}
	
}

void UltrasonicSensorManager::loop()
{
	timer->update();

	if (Model::motorController->isMoving == true && timerEventId == -1)
	{
		// start checking distance
		timerEventId = timer->every(sensorTick, checkDistance);
	}
}

UltrasonicSensorManager::UltrasonicSensorManager()
{
}


UltrasonicSensorManager::~UltrasonicSensorManager()
{
}


/*onSerialUltrasonic(String input)
{
	if (input == "getDistanceFront")
	{
		trace("Distance at front: " + (String)getDistance() + "cm");
	}
}
*/