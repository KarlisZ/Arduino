//#include <Timer.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "Main.h"
//#include "SerialManager.h"

Main app;

void setup()
{	
	app.setup();
}

void loop()
{
	app.loop();
}

void serialEvent()
{
	//SerialManager *serial = Model::serialManager;
	//serial->handleEvent();
}
