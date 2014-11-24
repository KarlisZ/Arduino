#include "SerialReader.h"

const char SerialReader::serialCommandTerminator = ';';

void SerialReader::setup()
{
	Serial.begin(9600);
	serialInput.reserve(200);
}

void SerialReader::onSerialCommand(String command)
{
	onSerialDebug(serialInput);
	//onSerialUltrasonic(serialInput);
}

void SerialReader::handleEvent()
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
}

void SerialReader::trace(String input)
{
	Serial.println("[Trace] " + input);
}

void SerialReader::onSerialDebug(String input)
{
	trace("Serial input received: " + input);

	if (input == "reset")
	{
		asm volatile ("  jmp 0");
	}
}
