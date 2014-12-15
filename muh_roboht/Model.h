#ifndef Model_h
#define Model_h

class MotorController;
class EventManager;
class SerialManager;

class Model
{
	public: 
		static void setup();
		static EventManager* evtMgr;
		static MotorController* motorController;
		static SerialManager* serialManager;
	private:
		
};


#endif