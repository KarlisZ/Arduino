#ifndef MotorController_h
#define MotorController_h

#include "Model.h"

class EventManager;
class SerialManager;

class MotorController 
{
public:
	void setup();
	void loop();

	void moveForward();
	void brake();
	void stopMotorOutputs();

	bool isMoving;

private:
	int areMotorsStopped;
	EventManager *evtMgr;
	SerialManager *serial;

	
	void subscribeEvents();
};

#endif