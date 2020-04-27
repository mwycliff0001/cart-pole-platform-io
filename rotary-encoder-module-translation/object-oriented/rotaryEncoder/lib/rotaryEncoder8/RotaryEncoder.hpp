/*

Title:   		RotaryEncoder
File Name: 		RotaryEncoder7
Purpose:		.
				.
				Header file for RotaryEncoder.cpp

				Purpose:  This module is intended
				to control the behaviour
				of Arduino-related rotary encoders.
				Doing so in an object oriented manner
				will make the code easier to read,
				implement, modify, and adjust.

                Recommended object instantiation code:

				rotaryEncoderController rotEncCx;
				encoder ENC1;
				encoder ENC2;
				encoder ENCN;
				rotEncSupervisor rSup;
				       
*/

#include "Arduino.h"
#include <string.h>
#include <math.h>

//forward declarations
class Encoder;
class RotaryEncoderController;
class RotaryEncoderSupervisor;

class Encoder
{
public:
Encoder();
~Encoder(){}
int CLK;
int DT;
void OnSetup(int clock_pin, int detector_pin);
};

class RotaryEncoderController {
public:
RotaryEncoderController();
~RotaryEncoderController(){}
int value;
int rotation;
int RotPosition;
bool LeftRight;
void OnSetup(Encoder * encoder);
int resolveEncoder(
					unsigned long global_counter,
                    unsigned long global_delay, 
                    Encoder * encoder,
                    RotaryEncoderSupervisor supervisor);
};

class RotaryEncoderSupervisor {
public:
RotaryEncoderSupervisor();
~RotaryEncoderSupervisor(){}
int GreenLed;
int RedLed;
int BlueLed;
void OnSetup(int green_pin, int red_pin, int blue_pin);
int superviseEncoder(RotaryEncoderController * rotary_encoder_controller);
};