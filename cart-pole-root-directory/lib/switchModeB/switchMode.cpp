/*

Name:   		switchMode.cpp()
Purpose:		.
				.
				Press a button to change modes.
				.
				.
Version:		A
				.
Date:           3.11.2020
Last Update:    4.05.2020
				.
				.
*/

#include "switchMode.hpp" 
#define WINDOW 2000
#define BOUNCE_DURATION 40

switchMode::switchMode()
    :
    buttonDelay(0),
    buttonPin(0),
    buttonState(0),
    clickCount(1),
    internalCounter(0),
    mode(0),
    superMode(0)

	{
        //delay(10);
		//Serial.print("\n\n... Attempting switchMode initialization ...\n");
	}


void switchMode::smOnSetup(int bP) {
   buttonPin = bP;
   pinMode(buttonPin,INPUT_PULLUP);
}


void switchMode::buttonPressed(unsigned long global_counter) {

	if (buttonState == digitalRead(buttonPin)) {}
    
    else {

	    delay(BOUNCE_DURATION);
	    buttonState = digitalRead(buttonPin);
	    buttonDelay = static_cast<unsigned int>( abs(global_counter - internalCounter) );
        //Serial.print("\n\nBUTTON DELAY     ");
        //Serial.print(buttonDelay);
	    if (buttonDelay < WINDOW) {
	        clickCount++;
	        internalCounter = global_counter;
        }
	    else internalCounter = global_counter;

    }
}

void switchMode::changeMode() {
	mode = clickCount;
	if ( mode % 6 != 0 ) {}
	else mode = 0;
}

//int switchMode::changeSuperMode() {
int switchMode::changeSuperMode(int option) {

    if (option == 0)
        clickCount = 5;
    else if (option == 1)
        clickCount = clickCount%5;
    else
        clickCount = clickCount%5;
    
    int var = clickCount%5;
    
	if      (var==4) 
	    return 4;
	else if (var==3) 
	    return 3;
	else if (var==2)
	    return 2;
	else if (var==1) 
	    return 1;
	else
	    return 5;
}

void switchMode::smInLoop(int option, unsigned long global_counter) {
    buttonPressed(global_counter);
    superMode = changeSuperMode(option);
}



