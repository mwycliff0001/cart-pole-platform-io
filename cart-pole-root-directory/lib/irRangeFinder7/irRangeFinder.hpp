/*

Name:   		irRangeFinder()
Purpose:		.
				.
				Header file for irRangeFinder.cpp
				Intended for inclusion in a main.cpp file to be compiled and loaded
                onto an arduino microcontroller using Atom Platform IO or some other
                toolchain.

                Recommended object instantiation:       irRangeFinder k2m;
*/

#include <Arduino.h>


class irRangeFinder;
class irRangeFinder
{
public:
irRangeFinder();
~irRangeFinder(){}

//PUBLIC VARIABLES
/*
char k2msg[100];
int clock_pulse;
int clock_delay;
int motor_speed;
bool motor_direction;
int pot_range;
double throttle;
//int motor_range; // 255 --> max pwm
*/
int ledPin;
int minValue;
int sensorValue;
int ledBrightness;
int analogReadPin;



//PUBLIC FUNCTIONS
/*
bool clockPulse();
bool clockPulse(int pulse, int delay);
//int clockPulse(int * pulse, int * delay, int option);
int setMotorParams(int * analog_reading);
int displayValues(int * analog_reading);
int displayValues(int * analog_reading, bool event);
*/

void irrfOnSetup(int lP, int mV, int aRp);
//void irrfInLoop();
int irrfInLoop();




};

