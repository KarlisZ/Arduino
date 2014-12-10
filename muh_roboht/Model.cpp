// 
// 
// 

#include "Model.h"
#include "Event.h"

EventManager* Model::evtMgr;// = new EventManager;
MotorController* Model::motorController;// = new MotorController();

int Model::isMovingAllowed = 0;

void Model::setup()
{
	evtMgr = new EventManager();
}
