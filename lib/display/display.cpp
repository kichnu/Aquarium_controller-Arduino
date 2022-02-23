
#include "display.h"


uint8_t squareChar[8]  = {0xf,0xf,0xf,0xf,0xf,0xf,0xf};
uint8_t emptyChar[8]  = {0x0,0x0,0x0,0x0,0x0,0x0,0x0};

uint8_t actualLine;
uint8_t *pointerActualLine = &actualLine;


int8_t actualStateMessageList[lengthMessagesList] = 
  {
	-1,
  1,
	0,
  0,
	0,
  0,
	0,
  0,
	0,
  0,
	0,
  0,
	-1,
};

LiquidCrystal_I2C lcd(0x27, DISPLAY_COL, DISPLAY_ROW); 

void initDisplay()
{
  lcd.init();                   
  lcd.backlight();
}

void showDecorators()
{
  lcd.setCursor((DISPLAY_COL - displHeader.length())/2, 0);
  lcd.print(displHeader);
  lcd.createChar(0, squareChar);

  lcd.setCursor(0, 0);
  lcd.write(0);
  lcd.setCursor(19, 0);
  lcd.write(0);
}

void changeStatusToOn(uint8_t messageNum)
{
 
  clearLine((messageNum + 1), 3, 17);
    uint8_t i = 0;
    for(; i < lengthMessagesList; i ++)
      {
       if (actualStateMessageList[i] != -1)
         {
           actualStateMessageList[i] = 0;
         }
     }
    actualStateMessageList[messageNum + 1] = 1;
    
}

void showInfo(uint8_t messageNum)
  {
    clearLine(1, 3, 17);
    lcd.setCursor(17, 1);
    printInfo(messageNum);
  
    if(messageNum < lengthMessagesList - 1)
      {
        clearLine(2, 3, 17);
        lcd.setCursor(17, 2);
        printInfo(messageNum + 1);
    
      }
    
    if(messageNum < lengthMessagesList - 2)
      {
        clearLine(3, 3, 17);  
        lcd.setCursor(17, 3);
        printInfo(messageNum + 2);
      }
  } 

void printInfo(uint8_t messageNum)
{
  switch (actualStateMessageList[messageNum])
  {
    case -1:
      lcd.print("---");
      break;

    case 0:
      lcd.print("OFF");
      break;

    case 1:
      lcd.print(" ON");
      break;
  }
}  

void showMessage(uint8_t messageNum)
{

  clearLine(1, 16, 0);
  lcd.setCursor(0, 1);
  lcd.print(MessagesList[messageNum]);

  if(messageNum < lengthMessagesList - 1)
  {
    clearLine(2, 16, 0);
    lcd.setCursor(0, 2);
    lcd.print(MessagesList[messageNum +1]);
  }
    
  if(messageNum < lengthMessagesList - 2)
  {
    clearLine(3, 16, 0);  
    lcd.setCursor(0, 3);
    lcd.print(MessagesList[messageNum +2]);
  }      
}

void clearLine(uint8_t lineNum, uint8_t colNum, uint8_t colStart) 
{
  uint8_t colStartCout = colStart;
  lcd.createChar(1, emptyChar);
  for(; colStart < (colNum + colStartCout); colStart++)
    {
      lcd.setCursor(colStart, lineNum);
      lcd.write(1);
    }
}

void clearDisplay()
{
  lcd.clear();
}


