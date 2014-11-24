#include "Arduino.h"

class EventType
{
public:
	static const char* MOTOR;
	static const char* MOTOR_FWD;
	static const char* MOTOR_REV;
	static const char* MOTOR_BRK;
	static const char* MOTOR_IDLE;


};

const char* EventType::MOTOR = "MOTOR";
const char* EventType::MOTOR_FWD = "MOTOR.FWD";
const char* EventType::MOTOR_REV = "MOTOR.REV";
const char* EventType::MOTOR_BRK = "MOTOR.BRK";
const char* EventType::MOTOR_IDLE = "MOTOR.IDLE";