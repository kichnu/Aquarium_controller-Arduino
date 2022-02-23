#include "controlRelays.h"

void setupPins()
{
  for( int CONNECTORS = dayLight; CONNECTORS <= socket; CONNECTORS ++)
  {
    pinMode(CONNECTORS, OUTPUT);
    digitalWrite(CONNECTORS, HIGH);
  } 
}

void writePin(uint16_t numProgram)
{
  Serial.println("numProgram");
  Serial.println(numProgram);

  uint8_t prog;
  
  digitalWrite(dayLight, prog = !((numProgram & 0b1)>>0));
  digitalWrite(eveninglight, prog = !((numProgram & 0b10)>>1));
  digitalWrite(circulationPump, prog = !((numProgram & 0b100)>>2));
  digitalWrite(wavesPump, prog = !((numProgram & 0b1000)>>3));
  digitalWrite(skimmer, prog = !((numProgram & 0b10000)>>4));
  digitalWrite(heater, prog = !((numProgram & 0b100000)>>5));
  digitalWrite(basementPump, prog = !((numProgram & 0b1000000)>>6));
  digitalWrite(transferPump, prog = !((numProgram & 0b10000000)>>7));
  digitalWrite(prepareWater, prog = !((numProgram & 0b100000000)>>8));
  digitalWrite(socket, prog = !((numProgram & 0b1000000000)>>9));
}

void setPins(int8_t *stateMessage, uint8_t messageNum)
  {  
    Serial.println("messageNum");
    Serial.println(messageNum);
    Serial.println("ON");
    Serial.println(stateMessage[messageNum]);

    if(stateMessage[messageNum + 1] == 1)
    {
      switch (messageNum + 1)
      {
      case 1:
        writePin(Working);
        break;
      case 2:
        writePin(Feeding);
        break;
      case 3:
        writePin(Water_change);
        break;
      case 4:
        writePin(Light_OFF);
        break;
      case 5:
        writePin(Pumps_OFF);
        break;
      case 6:
        writePin(Skimmer_OFF);
        break;
      case 7:
        writePin(Heater_OFF);
        break;
      case 8:
        writePin(Socket_OFF);
        break;
      case 9:
        writePin(Basement_pump_ON);
        break;
      case 10:
        writePin(Prepare_water_ON);
        break;
      case 11:
        writePin(Transfer_pump_ON);
        break;
      default:
        break;
      }
    }
}





