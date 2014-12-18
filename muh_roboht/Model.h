#ifndef Model_h
#define Model_h

class RobotButton;
class MotorController;
class EventManager;
class SerialManager;
class LcdManager;
class UltrasonicSensorManager;

class Model
{
	public: 
		static void setup();
		static RobotButton* button;
		static EventManager* evtMgr;
		static MotorController* motorController;
		static SerialManager* serialManager;
		static LcdManager* lcdManager;
		static UltrasonicSensorManager* usSensorManager;

	private:
		
};


#endif