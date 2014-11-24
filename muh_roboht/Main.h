#include "Arduino.h"
#include "RobotButton.h"
#include "SerialReader.h"

class Main
{
public:
	void setup();
	void loop();
	SerialReader serialReader;
private:
	RobotButton button;
};
