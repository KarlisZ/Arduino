#include "RobotButton.h"
#include "Model.h"
#include "Arduino.h"
//const EventManager Model::evtMgr;


// set pin numbers:
const int RobotButton::buttonPin = 2;     // the number of the pushbutton pin

RobotButton::RobotButton()
{
	buttonState = 0;
	Model::isMovingAllowed = 0;
	canChangeMotorState = 1;
}

void RobotButton::setupButton()
{
	// initialize the pushbutton pin as an input:
	pinMode(buttonPin, INPUT);
}

void RobotButton::loopButton()
{
	// read the state of the pushbutton value:
	buttonState = digitalRead(buttonPin);

	// check if the pushbutton is pressed.
	// if it is, the buttonState is HIGH:
	if (buttonState == HIGH && canChangeMotorState == 1)
	{
		canChangeMotorState = 0;

		if (Model::isMovingAllowed == 0)
		{
			Model::isMovingAllowed = 1;
		}
		else
		{
			Model::isMovingAllowed = 0;
		}
	}
	else if (buttonState == LOW)
	{
		canChangeMotorState = 1;
	}
}

