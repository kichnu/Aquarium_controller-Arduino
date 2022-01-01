
#include "Arduino.h"

            //paramiters of keyboard
const uint8_t numberOfRows = 5;
const uint8_t numberOfCol = 4;
uint8_t pinRow[numberOfRows] = {2, 3, 4, 5, 6}; //number of pin
uint8_t pinCol[numberOfCol] = {A0, A1, A2, A3}; //number of pin
uint8_t doubleClickPouse = 100;
uint8_t nextKeyTime = 1000;

            //auxiliary variables
bool keyPressed = false;
long int previousMillis = 0;
long int currenMillis = 0;

            //Prototype functions
void readKeyboard();
void checkMyKey(uint8_t i, uint8_t j);
void printKey(const char myString[]);

            //functions
void readKeyboard(){

  for(uint8_t i=0; i < numberOfRows; i++)
    {
      pinMode(pinRow[i], INPUT_PULLUP);

      for(uint8_t j=0; j < numberOfCol; j++)
      {
        pinMode(pinCol[j], OUTPUT);
        digitalWrite(pinCol[j], LOW);

        if((!digitalRead(pinRow[i]) && (keyPressed)))
          {
            currenMillis = millis();

            if (previousMillis == 0)
            {
              previousMillis = currenMillis;
            }
            
            if((currenMillis - doubleClickPouse > previousMillis))
            {
            checkMyKey(i, j);
            keyPressed = false;  
            }

            previousMillis = currenMillis;
          }

          else if(!(keyPressed))
          {
            currenMillis = millis();
            if (previousMillis == 0)
            {
              previousMillis = currenMillis;
            }

            if((currenMillis - nextKeyTime > previousMillis))
            {
            keyPressed = true;
            previousMillis = currenMillis;
            }
          }
        digitalWrite(pinCol[j], HIGH);
      }
      pinMode(pinRow[i], OUTPUT);
    }
}

void checkMyKey(uint8_t i, uint8_t j){
  if((i == 0)&&(j == 0))
    printKey("F1");
  else if((i == 0)&&(j == 1))  
    printKey("F2");
  else if((i == 0)&&(j == 2))  
    printKey("#");
  else if((i == 0)&&(j == 3))  
    printKey("*");
  else if((i == 1)&&(j == 0))  
    printKey("1");
  else if((i == 1)&&(j == 1))  
    printKey("2");
  else if((i == 1)&&(j == 2))  
    printKey("3");
  else if((i == 1)&&(j == 3))  
    printKey("Arrow Top");
  else if((i == 2)&&(j == 0))  
    printKey("4");
  else if((i == 2)&&(j == 1))  
    printKey("5");
  else if((i == 2)&&(j == 2))  
    printKey("6");
  else if((i == 2)&&(j == 3))  
    printKey("Arrow down");
  else if((i == 3)&&(j == 0))  
    printKey("7");
  else if((i == 3)&&(j == 1))  
    printKey("8");
  else if((i == 3)&&(j == 2))  
    printKey("9");
  else if((i == 3)&&(j == 3))  
    printKey("Esc");
  else if((i == 4)&&(j == 0))  
    printKey("Arrow left");
  else if((i == 4)&&(j == 1))  
    printKey("0");
  else if((i == 4)&&(j == 2))  
    printKey("Arrow right");
  else if((i == 4)&&(j == 3))  
    printKey("Enter");
}

void printKey(const char myString[])
{
  Serial.println(myString);
}