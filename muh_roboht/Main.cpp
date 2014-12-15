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

int freeRam()
{
	extern int __heap_start, *__brkval;
	int v;
	return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
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
