// 
// 
// 

#include "Model.h"
#include "Event.h"
#include "SerialManager.h"
#include "MotorController.h"
#include "LcdManager.h"
#include "UltrasonicSensorManager.h"
#include "RobotButton.h"

RobotButton* Model::button;
EventManager* Model::evtMgr;
MotorController* Model::motorController;
SerialManager* Model::serialManager;
LcdManager* Model::lcdManager;
UltrasonicSensorManager* Model::usSensorManager;


void Model::setup()
{
	button = new RobotButton();
	serialManager = new SerialManager();
	evtMgr = new EventManager();
	motorController = new MotorController();
	lcdManager = new LcdManager();
	usSensorManager = new UltrasonicSensorManager();
}
