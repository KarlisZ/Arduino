#include "LcdManager.h"
#include "Arduino.h"
#include "Event.h"
#include "EventType.h"
#include "Model.h"

#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

struct MotorEventListener : public EventTask
{
	using EventTask::execute;

	void execute(Event evt)
	{
		String extra = evt.extra;
		LcdManager *lcdM;
		lcdM = Model::lcdManager;

		if (extra == EventType::MOTOR_FWD)
		{
			lcdM->write("Moving forward");
		}
		else if (extra == EventType::MOTOR_REV)
		{
			lcdM->write("Moving backward");
		}
		else if (extra == EventType::MOTOR_BRK)
		{
			lcdM->write("Braking");
		}
		else if (extra == EventType::MOTOR_IDLE)
		{
			lcdM->write("Motors idle");
		}

	}

} MotorEventListener;

void LcdManager::setup()
{
	evtMgr = Model::evtMgr;

	backlightState = 0;

	lcd->begin(20, 4); //  LCD char grid

	lcd->setBacklightPin(BACKLIGHT_PIN, POSITIVE);

	lcd->home(); // go home
	subscribeEvents();
}

void LcdManager::subscribeEvents()
{
	evtMgr->subscribe(Subscriber(EventType::MOTOR, &MotorEventListener));
}


void LcdManager::write(String ipt)
{
	if (backlightState == 0)
	{
		lcd->setBacklight(HIGH);
		backlightState = 1;
	}

	//trace("Writing to LCD: " + ipt);
	lcd->clear();
	lcd->home();
	lcd->print(ipt);

}

LcdManager::LcdManager()
{
	lcd = new LiquidCrystal_I2C(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
}


LcdManager::~LcdManager()
{
	delete lcd;
}
