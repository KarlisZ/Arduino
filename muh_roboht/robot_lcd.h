#include "Arduino.h"

#define I2C_ADDR    0x3F
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;
int backlightState = 0;

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

EventManager evtMgr;

void writeToLcd(String ipt)
{
	if (backlightState == 0)
	{
		lcd.setBacklight(HIGH);
		backlightState = 1;
	}

	trace("Writing to LCD: " + ipt);
	lcd.clear();
	lcd.home();
	lcd.print(ipt);
}


struct MotorEventListener : public EventTask
{
	using EventTask::execute;

	void execute(Event evt)
	{
		String extra = evt.extra;

		if (extra == EventType::MOTOR_FWD)
		{
			writeToLcd("Moving forward");
		}
		else if (extra == EventType::MOTOR_REV)
		{
			writeToLcd("Moving backward");
		}
		else if (extra == EventType::MOTOR_BRK)
		{
			writeToLcd("Braking");
		}
		else if (extra == EventType::MOTOR_IDLE)
		{
			writeToLcd("Motors idle");
		}

	}

} MotorEventListener;

void subscribeEvents()
{
	evtMgr = Model::evtMgr;
	
	evtMgr.subscribe(Subscriber(EventType::MOTOR, &MotorEventListener));
}

void setupLcd()
{
  lcd.begin (20,4); //  LCD char grid

  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  
  lcd.home (); // go home
  subscribeEvents();
}




