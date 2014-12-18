#include "Main.h"
#include "Model.h"
#include "RobotButton.h"
#include "MotorController.h"
#include "SerialManager.h"
#include "LcdManager.h"
#include "UltrasonicSensorManager.h"

void Main::setup()
{
	Model::setup();

	serial = Model::serialManager;
	serial->setup();

	button = Model::button;
	button->setup();

	motors = Model::motorController;
	motors->setup();

	lcd = Model::lcdManager;
	lcd->setup();

	usSensor = Model::usSensorManager;
	usSensor->setup();

	serial->trace("Setup Complete");

}


void Main::loop()
{
	button->loop();
	usSensor->loop();
}
