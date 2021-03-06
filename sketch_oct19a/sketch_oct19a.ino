#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

char* replies[] = {"Yes", "Most likely", "Certainly", "Outlook good", "Unsure", "Ask again", "Doubtful", "No"};

void setup()
{
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop()
{
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState)
  {
    if(switchState == LOW)
    {
      reply = random(8); 
    }
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The ball says:");
  lcd.setCursor(0,1); 
  


  lcd.print(replies[reply]);
  
  prevSwitchState = switchState;
}
