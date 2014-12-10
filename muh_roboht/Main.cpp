#include "Main.h"
#include "Model.h"

void Main::setup()
{
	//motors = Model::motorController;
	serialReader.setup();

	Model::setup();
	button.setupButton();
	motors.setup();

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
	motors.loop();
	/*
	loopButton();
	loopMotors();
	loopUltrasonicSensor();
	*/
}
