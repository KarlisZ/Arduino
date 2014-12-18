#pragma once

class Timer;
class EventManager;

class UltrasonicSensorManager
{
public:
	UltrasonicSensorManager();
	~UltrasonicSensorManager();
	
	void setup();
	void loop();

	long getDistance();
	Timer *timer;
	int timerEventId;
private:
	long microsecondsToCentimeters(long microseconds);

	EventManager *evtMgr;
	int sensorTick;
};

