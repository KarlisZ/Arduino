#ifndef Main_h
#define Main_h

class RobotButton;
class MotorController;
class SerialManager;
class LcdManager;
class UltrasonicSensorManager;

class Main
{
public:
	void setup();
	void loop();

private:
	RobotButton *button;
	MotorController *motors;
	SerialManager *serial;
	LcdManager *lcd;
	UltrasonicSensorManager *usSensor;
};

#endif