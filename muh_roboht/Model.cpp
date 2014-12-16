// 
// 
// 

#include "Model.h"
#include "Event.h"
#include "SerialManager.h"
#include "MotorController.h"
#include "LcdManager.h"

EventManager* Model::evtMgr;
MotorController* Model::motorController;
SerialManager* Model::serialManager;
LcdManager* Model::lcdManager;


void Model::setup()
{
	serialManager = new SerialManager();
	evtMgr = new EventManager();
	motorController = new MotorController();
	lcdManager = new LcdManager();
}
