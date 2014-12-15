#ifndef SerialManager_h
#define SerialManager_h

#include "Arduino.h"

class SerialManager
{
public:
	void setup();
	//void handleEvent();
	void trace(String input);
private:
	//void onSerialDebug(char input);
	//void onSerialUltrasonic(char input);
	//void onSerialCommand(char command);
	//String serialInput;
	//static const char serialCommandTerminator;
};

#endif