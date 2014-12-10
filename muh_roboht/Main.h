#ifndef Main_h
#define Main_h

#include "RobotButton.h"
#include "SerialReader.h"
#include "MotorController.h"

class Main
{
public:
	void setup();
	void loop();
	SerialReader serialReader;

private:
	RobotButton button;
	MotorController motors;
};

#endif