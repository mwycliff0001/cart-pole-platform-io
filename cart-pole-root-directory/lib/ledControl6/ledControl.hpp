#include <Arduino.h>

class ledControl;
class ledControl
{
public:
ledControl();
~ledControl(){}

//PUBLIC VARIABLES
bool internalLedOnOff;
bool externalLedOnOff;

//PUBLIC FUNCTIONS

void onSetup();
void internalLedBlink(); 
void internalLedBlink(unsigned long global_clock, unsigned long global_delay); 
void externalLedBlink(int externalLed);
void externalLedBlink(unsigned long global_clock, unsigned long global_delay, int externalLed);

};


