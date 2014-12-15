// 
// 
// 

#include "Model.h"
#include "Event.h"
#include "SerialManager.h"
#include "MotorController.h"

EventManager* Model::evtMgr;
MotorController* Model::motorController;
SerialManager* Model::serialManager;


void Model::setup()
{
	serialManager = new SerialManager();
	evtMgr = new EventManager();
	motorController = new MotorController();
}
