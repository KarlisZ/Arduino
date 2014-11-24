#include "Main.h"
#include "Arduino.h"


void Main::setup()
{

	button.setupButton();
	serialReader.setup();

	serialReader.trace("Setup Complete");

	/*setupDebug();
	setupSerialReader();
	setupButton();
	setupMotors();
	setupLcd();
	setupUltrasonicSensor();

	trace("setup complete");
	*/
}

void Main::loop()
{
	/*
	loopButton();
	loopMotors();
	loopUltrasonicSensor();
	*/
}
