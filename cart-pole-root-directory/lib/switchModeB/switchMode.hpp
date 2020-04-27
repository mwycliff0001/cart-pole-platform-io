/*

Name:   		switchMode()
Purpose:		.
				.
				Header file for switchMode.cpp
				Intended for inclusion in a main.cpp file to be compiled and loaded
                onto an arduino microcontroller using Atom Platform IO or some other
                toolchain.

                Recommended object instantiation:       switchMode k2m;
*/

#include <Arduino.h>
//#define WINDOW 4000
//#define BOUNCE_DURATION 40

class switchMode;
class switchMode
{
public:
switchMode();
~switchMode(){}

//PUBLIC VARIABLES

unsigned int buttonDelay;
int buttonPin;
bool buttonState;
int clickCount;
unsigned long internalCounter;
unsigned int mode;
unsigned int superMode;

//PUBLIC FUNCTIONS

void smOnSetup(int bP);
void buttonPressed(unsigned long global_counter);
void changeMode();
int changeSuperMode(int option);
void smInLoop(int option, unsigned long global_counter);

};

