#include "Arduino.h"

class SerialReader
{
public:
	void setup();
	void handleEvent();
	void trace(String input);
	void onSerialDebug(String input);
	void onSerialUltrasonic(String input);
private:
	void onSerialCommand(String command);
	String serialInput;
	static const char serialCommandTerminator;
};
