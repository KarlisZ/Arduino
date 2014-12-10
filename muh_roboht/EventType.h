#ifndef EventType_h
#define EventType_h

class EventType
{
public:
	static const char* MOTOR;
	static const char* MOTOR_FWD;
	static const char* MOTOR_REV;
	static const char* MOTOR_BRK;
	static const char* MOTOR_IDLE;

	static const char* BUTTON;
	static const char* BUTTON_DOWN;


};

const char* EventType::MOTOR = "MOTOR";
const char* EventType::MOTOR_FWD = "MOTOR.FWD";
const char* EventType::MOTOR_REV = "MOTOR.REV";
const char* EventType::MOTOR_BRK = "MOTOR.BRK";
const char* EventType::MOTOR_IDLE = "MOTOR.IDLE";

const char* EventType::BUTTON = "BUTTON";
const char* EventType::BUTTON_DOWN = "BUTTON_DOWN";

#endif