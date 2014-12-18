#include "RobotButton.h"
#include "Model.h"
#include "Arduino.h"
#include "Event.h"
#include "EventType.h"


// set pin numbers:
const int RobotButton::buttonPin = 2;     // the number of the pushbutton pin

RobotButton::RobotButton()
{
	buttonState = 0;
	canChangeButtonState = true;
}

void RobotButton::setup()
{
	evtMgr = Model::evtMgr;

	// initialize the pushbutton pin as an input:
	pinMode(buttonPin, INPUT);
}

void RobotButton::loop()
{
	// read the state of the pushbutton value:
	buttonState = digitalRead(buttonPin);
	//Serial.println("button " + (String)buttonState);
	//Serial.println("state " + (String)canChangeButtonState);

	// check if the pushbutton is pressed.
	// if it is, the buttonState is HIGH:
	if (buttonState == HIGH && canChangeButtonState == true)
	{
		canChangeButtonState = false;

		Event downEvent = Event(EventType::BUTTON, EventType::BUTTON_DOWN);
		evtMgr->trigger(downEvent);
	}
	else if (buttonState == LOW)
	{
		canChangeButtonState = true;

		Event upEvent = Event(EventType::BUTTON, EventType::BUTTON_UP);
		evtMgr->trigger(upEvent);
	}
}

