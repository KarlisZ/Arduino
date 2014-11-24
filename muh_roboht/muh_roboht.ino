#include "Event.h"
#include <Timer.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
/*#include "EventType.h"
#include "Model.h"



#include "debug.h"
#include "RobotButton.h"
#include "robot_lcd.h"
#include "motor_control.h"
#include "ultrasonic_sensor.h"
#include "serial_reader.h"
*/
//#include "SerialReader.h"
#include "Main.h"

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
	app.serialReader.handleEvent();
}
