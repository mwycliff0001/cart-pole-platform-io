/*

Title:   		KnobToMotor4
File Name: 		KnobToMotor()
Purpose:		.
				.
				Header file for KnobToMotor.cpp
				Intended for inclusion in a main.cpp file to be compiled and loaded
                onto an arduino microcontroller using Atom Platform IO or some other
                toolchain.

                Recommended object instantiation:       KnobToMotor k2m;
*/

#include "Arduino.h"
#include <string.h>
#include <math.h>


class KnobToMotor;
class KnobToMotor
{
public:
KnobToMotor();
~KnobToMotor(){}

//PUBLIC VARIABLES
char k2msg[100];
int clock_pulse;
int clock_delay;
int motor_speed;
bool motor_direction;
int pot_range;
double throttle;
//int motor_range; // 255 --> max pwm


//PUBLIC FUNCTIONS
bool clockPulse();
bool clockPulse(int pulse, int delay);
int setMotorParams(int * analog_reading);
int setMotorParams(int option, int * analog_reading);
int displayValues(int * analog_reading);
int displayValues(int * analog_reading, bool event);

};

// NOTE :  YOU MAY AT SOME POINT WANT TO TUNE / ALTER K2MSG CHAR ARRAY TO A BUFFER OF A SET SIZE THAT WILL OCCUPY A RELIABLY SIZED SLICE OF THE SCREEN SO THAT EVERYTIME IT PRINTS, IT TAKES UP THE SAME AMOUNT OF SPACE, AND LINES UP NICE AND NEAT.



