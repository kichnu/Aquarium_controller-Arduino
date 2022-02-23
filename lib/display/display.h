#ifndef display_h
#define display_h


#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DISPLAY_COL 20
#define DISPLAY_ROW 4

const String displHeader = "SELECTED PROGRAM";
extern int8_t actualStateMessageList[];

const uint8_t lengthMessagesList = 13;
const char MessagesList[lengthMessagesList][DISPLAY_COL]= 
  {
    "----------------",
	"Working",
	"Feeding",
	"Water change",
	"Light OFF",
	"Pumps OFF",
	"Skimmer OFF",
	"Heater OFF",
	"Socket OFF",
	"Basement pump ON",
    "Prepare water ON",
	"Transfer pump ON",
    "----------------",
  };
  

const int8_t settingPatternForWorking[]= 
  {
	-1,    
    1,
	0,
    0,
	0,
    -1,
    1,
	0,
    0,
	1,
    1,
	1,
    0,
	0,
	1,
	0,
    1,
	-1,
  };
const int8_t settingPatternForFeeding[]= 
{
	-1,
    0,
	1,
    0,
	0,
    -1,
    1,
	0,
    1,
	0,
    1,
	1,
    0,
	0,
	1,
	0,
    1,
	-1
  };
const char settingPatternForPumpOff[]= 
{
	-1,
    0,
	0,
    1,
	0,
    -1,
    1,
	0,
    0,
	0,
    0,
	1,
    0,
	0,
	1,
	0,
    1,
	-1
};
const char settingPatternForWaterChange[]= 
{
	-1,
    0,
	0,
    0,
	1,
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
    1,
	-1
};

void initDisplay();
void showDecorators();
void showMessage(uint8_t messageNum);
void showInfo(uint8_t messageNum);
void printInfo(uint8_t messageNum);
void clearLine(uint8_t lineNum, uint8_t colNum, uint8_t colStart);
void clearDisplay();
void changeStatusToOn(uint8_t messageNum);


#endif
