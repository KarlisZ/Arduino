#ifndef Model_h
#define Model_h

//#include "MotorController.h"
//#include "Event.h"

class MotorController;
class EventManager;

class Model
{
	public: 
		static void setup();
		static EventManager* evtMgr;
		static MotorController* motorController;
		static int isMovingAllowed;
	private:
		
};


#endif