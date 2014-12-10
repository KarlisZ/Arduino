#ifndef RobotButton_h
#define RobotButton_h

class RobotButton
{
public:
	void loopButton();
	void setupButton();
	RobotButton();
private:
	static const int buttonPin;
	int buttonState;
	int canChangeMotorState;
	
};

#endif