#ifndef MotorController_h
#define MotorController_h

//#include "Event.h"
#include "Model.h"

//class Model;
class EventManager;

class MotorController 
{
public:
	//MotorController() : evtMgr(Model::evtMgr) {};
	void setup();
	void loop();

	void moveForward();
	void brake();
	void stopMotorOutputs();

private:
	int isMoving;
	int areMotorsStopped;
	EventManager *evtMgr;

	
	void subscribeEvents();
};

#endif