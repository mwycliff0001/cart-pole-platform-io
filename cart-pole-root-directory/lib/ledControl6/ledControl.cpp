/*

Name:   		ledControl.cpp

Version:   		6
Purpose:

				Blink the onboard led.

Author:		    Matthew Wycliff

Date:		    3.11.2020
Last Update:    3.12.2020

				.

*/

#include "ledControl.hpp"


ledControl::ledControl()
    :
    internalLedOnOff(0),
    externalLedOnOff(0)

	{
        //delay(10);
		//Serial.print("\n\n... Attempting ledMode initialization ...\n");
	}


void ledControl::onSetup() {
  pinMode(LED_BUILTIN, OUTPUT);
}


void ledControl::internalLedBlink() {
        digitalWrite(LED_BUILTIN, !internalLedOnOff);
        internalLedOnOff = !internalLedOnOff;
}


void ledControl::internalLedBlink(unsigned long global_clock, unsigned long global_delay) {

    if( global_clock % global_delay != 0 ) {}
    else {
        digitalWrite(LED_BUILTIN, !internalLedOnOff);
        internalLedOnOff = !internalLedOnOff;
    } 
}


void ledControl::externalLedBlink(int externalLed) {
        digitalWrite(externalLed, !externalLedOnOff);
        externalLedOnOff = !externalLedOnOff;
}


void ledControl::externalLedBlink(unsigned long global_clock, unsigned long global_delay, int externalLed) {

    if( global_clock % global_delay != 0 ) {}
    else {
        digitalWrite(externalLed, !externalLedOnOff);
        externalLedOnOff = !externalLedOnOff;
    } 
}

