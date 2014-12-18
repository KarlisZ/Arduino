#ifndef RobotButton_h
#define RobotButton_h

class EventManager;

class RobotButton
{
public:
	void loop();
	void setup();
	RobotButton();
private:
	static const int buttonPin;
	int buttonState;
	bool canChangeButtonState;
	EventManager *evtMgr;
	
};

#endif