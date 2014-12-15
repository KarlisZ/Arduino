#ifndef MotorController_h
#define MotorController_h

#include "Model.h"

class EventManager;
class SerialManager;

class MotorController 
{
public:
	void setup();

	void moveForward();
	void brake();
	
	bool isMoving;

private:
	void stopMotorOutputs();
	void subscribeEvents();

	int areMotorsStopped;
	EventManager *evtMgr;
	SerialManager *serial;
	
};

#endif