/*
Name:   		cart-pole-platform-io

Author:			Matthew Wycliff  Wycliff8549@UHCL.edu

Purpose:	    The purpose of this file
				is to control the behaviour of a
				cart-pole system.  When compiled
				and loaded onto an Arduino Nano
				ATMEGA-328 using the Atom-Platform-IO
				ToolChain, this code will allow the
				user to:

				* Control the speed and direction
				  of the carriage.
				
				* Use a button to switch between
				  five separate control modes.

				* Read serial data coming
				  from two separate encoders.

Date:	        April 26 2020
Last Update:    April 26 2020

Build / Compile:    This code is meant to be built
                    using the Atom PlatformIO toolchain.

** Make sure you select the ATMega328 (old bootloader)
if it asks you for a processor.

BUILD COMMAND:  First execute the build command located
                in the upper left corner of the Platform-IO
                GUI.  Next, click the upload button right
				below it.  If it kicks back an error,
				open a fresh terminal and execute the
				following command:
				
				$ chmod +777 /dev/ttyUSB0

SERIAL MONITOR: 
                Once the code is loaded onto your MCU
				and it is running, to view the serial
				print statements, run the serial monitor
				by pressing Shift+Cmd+T or clicking the
				Terminal button which is 3rd from the
				bottom left.
				Then enter this terminal command:
				
				$ pio device monitor

*/

#include <Arduino.h>
#include <KnobToMotor.hpp>
#include <Hbridge.hpp>
#include <nanoled.hpp>
#include <irRangeFinder.hpp>
#include <switchMode.hpp>
#include <ledControl.hpp>
#include <RotaryEncoder.hpp>
#define in1 6
#define in2 7
#define BUTTON 10
#define YELLOWLED 2

//instantiate objects
Hbridgeclass hbx;
KnobToMotor k2m;
irRangeFinder irrf;
switchMode sm;
ledControl ledctrl;

//global vars
long gcp = 0;			//clock pulse
long gcdh = 400;		//
long gcd = gcdh/1;		//clock delay

//object instantions
RotaryEncoderController rotEncCx1;
RotaryEncoderController rotEncCx2;
Encoder ENC1;
Encoder ENC2;
RotaryEncoderSupervisor rSup1;
RotaryEncoderSupervisor rSup2;

double scalar = 0.1;
double arg1 = 0;
int pot_pin = 0;
int * potpinptr = &pot_pin;
int boundaryFlagLeft = 1;

void setup() {

	Serial.begin(9600);
	ENC1.OnSetup(11,12);		// CLK = 12  DT = 11
    ENC2.OnSetup(3,4);          // CLK = 12  DT = 11
	rotEncCx1.OnSetup(&ENC1);
    rotEncCx2.OnSetup(&ENC2);
	rSup1.OnSetup(13,13,13);
	rSup2.OnSetup(13,13,13);

	setupOnBoardLed();
    k2m.pot_range = 1020;
    k2m.throttle = 0.6;
    hbx.motor_pwm_pin_number = 9;
    irrf.irrfOnSetup(8,800,5);
    sm.smOnSetup(BUTTON);
    ledctrl.onSetup();
    pinMode(YELLOWLED, OUTPUT);
  }


void displayMode() {

    Serial.print("\nMODE    ");
    Serial.print(sm.superMode);
    Serial.print("   ccnt    ");
    Serial.print(sm.clickCount);
    Serial.print("\n\n");
}

void displayAll() {
	displayMode();
    Serial.print("    boundaryflag    [");
    Serial.print(boundaryFlagLeft);
    Serial.print("]    ");
	k2m.displayValues(potpinptr, 1);
}

void levelOneAction(int option) {
    pot_pin = analogRead(0);
	k2m.setMotorParams(option, potpinptr);
    hbx.resolveMotorParameters(k2m.motor_direction, k2m.motor_speed, in1, in2);
    boundaryFlagLeft = irrf.irrfInLoop();
    rotEncCx1.resolveEncoder(gcp,gcd,&ENC1,rSup1);
	rotEncCx2.resolveEncoder(gcp,gcd,&ENC2,rSup2);
}

void loop() {

    while(sm.superMode == 5){
        levelOneAction(0);
        gcp++; // increment global clock pulse
        ledctrl.externalLedBlink(gcp,gcd/8,YELLOWLED);
        sm.smInLoop(boundaryFlagLeft, gcp); //state machine in loop
        if (gcp%(gcd*10) == 0) {
            displayAll();
        }
    }

	while(sm.superMode == 4){
        levelOneAction(2);
        gcp++;
        ledctrl.externalLedBlink(gcp,gcd/4,YELLOWLED);
        ledctrl.internalLedBlink(gcp,gcd/3);
        sm.smInLoop(boundaryFlagLeft, gcp);
        if (gcp%(gcd*10) == 0) {
            displayAll();
        }
    }

    while(sm.superMode == 3){
        levelOneAction(1);
        gcp++;
        ledctrl.externalLedBlink(gcp,gcd/2,YELLOWLED);
        sm.smInLoop(boundaryFlagLeft, gcp);
        if (gcp%(gcd*10) == 0) {
            displayAll();
        }
    }

    while(sm.superMode == 2){
        levelOneAction(1);
        gcp++;
        ledctrl.externalLedBlink(gcp,gcd/1,YELLOWLED);
        sm.smInLoop(boundaryFlagLeft, gcp);
        if (gcp%(gcd*10) == 0) {
            displayAll();
        }
    }

    while(sm.superMode == 1){
        levelOneAction(2);
        gcp++;
        ledctrl.externalLedBlink(gcp,gcd/1,YELLOWLED);
        ledctrl.internalLedBlink(gcp,gcd/1);
        sm.smInLoop(boundaryFlagLeft, gcp);
       if (gcp%(gcd*10) == 0) {
            displayAll();
        }
    }
    gcp++; // increment global clock pulse
    sm.smInLoop(boundaryFlagLeft, gcp);
}
