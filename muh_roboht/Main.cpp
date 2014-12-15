#include "Main.h"
#include "Model.h"

void Main::setup()
{
	Model::setup();

	serial = Model::serialManager;
	serial->setup();

	motors = Model::motorController;
	motors->setup();

	button.setup();

	serial->trace("Setup Complete");	

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
	/*SerialReader *serial;
	serial = Model::serialReader;
	serial->trace("Ram left: " + (String)freeRam());
	*/
	//motors.loop();
	button.loop();
	/*
	loopButton();
	loopMotors();
	loopUltrasonicSensor();
	*/
}
