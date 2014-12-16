#ifndef Main_h
#define Main_h

#include "RobotButton.h"
#include "MotorController.h"
#include "SerialManager.h"
#include "LcdManager.h"

class Main
{
public:
	void setup();
	void loop();

private:
	RobotButton button;
	MotorController *motors;
	SerialManager *serial;
	LcdManager *lcd;
};

#endif