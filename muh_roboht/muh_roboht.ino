#include <Timer.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#include "Main.h"

Main app;

void setup()
{	
	app.setup();
}

void loop()
{
	//app.loop();
}

void serialEvent()
{
	//app.serialReader.handleEvent();
}
