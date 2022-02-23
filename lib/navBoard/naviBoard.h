
#ifndef naviBoard_h
#define naviBoard_h
#include <Arduino.h>
#include "display.h"

extern uint8_t actualMessageNum;

void readBoard();
void checkMyKey(uint8_t i);
void printKey(String myString);
void printNum(uint8_t num);
void printList(int8_t list[], uint8_t lengthList);
void nextLine();
void previousLine();
uint8_t getActualMessageNum();

#endif