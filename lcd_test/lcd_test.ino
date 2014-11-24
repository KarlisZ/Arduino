#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const String onSwitchDownText = String("ur a nosey lil faget arent cha");
const String defaultText = String("what does this button do?");

const int switchPin = 6;
const int charsPerLine = 16;
const int numLines = 2;

int switchState = 0;

void setup()
{
  lcd.begin(charsPerLine, numLines);
  pinMode(switchPin, INPUT); 
}

void loop()
{
  switchState = digitalRead(switchPin);
  if(switchState == 1)
  {
    onSwitchDown();    
  }
  else
  {
    printDefault(); 
  }
}

void onSwitchDown()
{
  printToLines(onSwitchDownText);
}

void printDefault()
{
  printToLines(defaultText);
}

void printToLines(String text)
{
  lcd.clear();
  
  int* numWords;
  String words[32];
  setWords(text, words, numWords);  
  
  
  char* lines[numLines];
  String line = String("");
  int lineLength;
  int curWord = 0;
  char* lineAsCharArray;
  char* buffer;
  for(int i=0; i<numLines; i++ )
  {
    // fill line
    while(lineLength<=charsPerLine)
    {
       words[curWord].toCharArray(buffer, charsPerLine);
       line += buffer;
       curWord++;
       lineLength = String(line.concat(words[curWord])).length();
    }
    
    lineLength = 0;
    line = String("");
    
    // print
    lcd.setCursor(0,i);
    lcd.print(line);
  }
}

void setWords(String text, String* aWords, int* aNumWords)
{
  String* words[32];
  int l = text.length();
  String character;
  int pos = 0;
  int* numWords = 0;
  String space = String(" ");
  
  // get words
  for(int i = 0; i<l-1; i++)
  {
    character = String(text.charAt(i));
    if(character == space)
    {
      words[numWords] = text.substring(pos, i);
      numWords += 1;
      pos = i;
    }    
  }
  
  aNumWords = numWords;
  aWords = words;
}

int getCharArrayLength(char arr)
{
  return sizeof(arr)/sizeof(arr[0]);
}
