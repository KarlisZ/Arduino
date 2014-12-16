#pragma once

#include "Arduino.h"

class LiquidCrystal_I2C;
class EventManager;

class LcdManager
{
public:
	LcdManager();
	~LcdManager();
	void setup();
	void write(String ipt);
private:
	void subscribeEvents();

	LiquidCrystal_I2C *lcd;
	EventManager *evtMgr;
	int backlightState;
};

