
#ifndef controlRelays_h
#define controlRelays_h

#include <Arduino.h>
#include "naviBoard.h"
#include "display.h"

const typedef enum 
{
    dayLight = 2,
    eveninglight = 3,
    circulationPump = 4,
    wavesPump = 5,
    skimmer = 6,
    heater = 7,
    basementPump = 8,
    prepareWater = 9,
    transferPump = 10,
    socket = 11
} CONNECTORS;

const typedef enum
{
    Working = 0b1000111111,
	Feeding = 0b1000110111,
	Water_change = 0b1000000011,
	Light_OFF = 0b1000111100,
	Pumps_OFF = 0b1000100011,
	Skimmer_OFF = 0b1000101111,
	Heater_OFF = 0b1000011111,
	Socket_OFF = 0b0000111111,
	Basement_pump_ON = 0b1001111111,
    Prepare_water_ON = 0b1010111111,
	Transfer_pump_ON = 0b1100111111,
} PROGRAMS;

void setupPins();
void setPins(int8_t *stateMessage, uint8_t messageNum);
void writePin(uint_fast16_t numProgram);

#endif