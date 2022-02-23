
#include "naviBoard.h"
#include "controlRelays.h"

bool keyPressed = false;
long int previousMillis = 0;
// long int currentMillis = 0;
static const uint8_t numberOfKeys = 5;
static const uint8_t pinKeys[numberOfKeys] = {A5, A4, A3, A2, A1}; //number of pin keyboard
uint8_t joinPin = A0;    // join of pin keyboard
uint8_t doubleClickPouse = 50;
uint16_t nextKeyTime = 300;

uint8_t actualMessageNum = 0;

void readBoard()
{
  for(int i=0; i < numberOfKeys; i++)
  {
    pinMode(pinKeys[i], INPUT_PULLUP);    
    pinMode(joinPin, OUTPUT);
    digitalWrite(joinPin, LOW);

    if((!digitalRead(pinKeys[i]) && (keyPressed)))
    {
            
      if (previousMillis == 0)
      {
        previousMillis = millis();
      }
            
      if((millis() - doubleClickPouse > previousMillis))
      {
        checkMyKey(i);
        keyPressed = false;  
      }
        previousMillis = millis();
    }

    else if(!(keyPressed))
    {
      if (previousMillis == 0)
      {
        previousMillis = millis();
      }

      if((millis() - nextKeyTime > previousMillis))
      {
        keyPressed = true;
        previousMillis = millis();
      }
          
      digitalWrite(joinPin, HIGH);
    }
      pinMode(pinKeys[i], OUTPUT);
  }
}

void checkMyKey(uint8_t key)
{
  showDecorators();
  switch (key)
  {
    case 0:
    printKey("NEXT");
    changeStatusToOn(actualMessageNum);
    showInfo(actualMessageNum);
    break;

  case 1:
    printKey("BEFORE");
    changeStatusToOn(actualMessageNum);
    showInfo(actualMessageNum);
    break;

  case 2:
    previousLine();
    printNum(actualMessageNum);
    printList(actualStateMessageList, lengthMessagesList);
    break;

  case 3:
    nextLine();
    printNum(actualMessageNum);
    printList(actualStateMessageList, lengthMessagesList);
    break;

  case 4:
     printKey("SEL");
     setPins(actualStateMessageList, actualMessageNum);
    
    break;
  
    default:
    break;
  }
}

void nextLine()
{
  if(actualMessageNum < lengthMessagesList -3)
  {
    actualMessageNum ++;
  }

  showMessage(actualMessageNum);
  showInfo(actualMessageNum);
}

void previousLine()
{
  if(actualMessageNum > 0)
    {
      actualMessageNum --;
    }
 

  showMessage(actualMessageNum);
  showInfo(actualMessageNum);
}


// Debugging @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void printKey(String myString)
{
  Serial.println(myString);
}

void printNum(uint8_t num)
{
  Serial.println(num);
  Serial.println("%%%%%%%%%%%%%%");
}

void printList(int8_t list[], uint8_t lengthList)
{
  int8_t i = 0;

  for(; i < lengthList; i++)
  {
    Serial.print(list[i]);

  }
  Serial.print("\n\r");
}