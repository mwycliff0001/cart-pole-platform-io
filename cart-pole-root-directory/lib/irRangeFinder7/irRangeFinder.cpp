/*

Title:   		irRangeFinder7
File Name: 		irRangeFinder.cpp()
Purpose:		
				Turn off an LED as soon as an
				object gets within range.

Hardware:		This involves an IR Transmitter / Receiver.


*/

#include "irRangeFinder.hpp" 

irRangeFinder::irRangeFinder()
    :
    analogReadPin(0),
    ledBrightness(0),
    ledPin(0),
    minValue(0),
    sensorValue(0)
	{
		//Serial.print("\n\n\n...... Attempting irRangeFinder initialization ........\n");
	}

void irRangeFinder::irrfOnSetup(int lP, int mV, int aRp) {
   ledPin = lP;
   minValue = mV;
   analogReadPin = aRp;
   pinMode(ledPin,OUTPUT);
}

//void irRangeFinder::irrfInLoop() {
int irRangeFinder::irrfInLoop() {
	sensorValue = analogRead(analogReadPin);
     bool state = 0;
     state = (sensorValue > minValue) ? 1 : 0;
     digitalWrite(ledPin,state);
     return state;
}

