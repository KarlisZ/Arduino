#include "SerialManager.h"

//const char SerialManager::serialCommandTerminator = ';';

void SerialManager::setup()
{
	Serial.begin(921600);
	Serial.flush();
	//serialInput.reserve(200);
	delay(100);
}

/*void SerialManager::onSerialCommand(char command)
{
	onSerialDebug(serialInput);
	//onSerialUltrasonic(serialInput);
}*/

/*
void SerialManager::handleEvent()
{
	while (Serial.available())
	{
		// get the new byte:
		char inChar = (char)Serial.read();

		if (inChar == serialCommandTerminator)
		{
			onSerialCommand(serialInput);
			serialInput = "";
		}
		else
		{
			serialInput += inChar;
		}
	}
}*/

void SerialManager::trace(String input)
{
	Serial.println("[Trace] " + input);
}

/*
void SerialManager::onSerialDebug(char input)
{
	trace("Serial input received: " + input);

	if (input == "reset")
	{
		asm volatile ("  jmp 0");
	}
}
*/