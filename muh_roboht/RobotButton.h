

class RobotButton
{
public:
	void loopButton();
	void setupButton();
	RobotButton();
private:
	static const int buttonPin;
	int buttonState;
	int isMovingAllowed;
	int canChangeMotorState;
	
};