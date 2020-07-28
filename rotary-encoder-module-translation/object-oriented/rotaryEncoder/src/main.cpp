 /*
   TITLE:       		ROTARYENCODER
   AUTHOR:      		MATTHEW WYCLIFF
   DATE:        		4.24.2020
   DESCRIPTION: 		ROTARY ENCODER

   NOTE:            This is an object
                    oriented based permutation
                    of Daniel Vandenbrande's
                    c++ rotary encoder code
		    for Arduino.
 */

#include <Arduino.h>
#include <RotaryEncoder.hpp>

long gcp = 0;
long gcdh = 400;
long gcd = gcdh/1;

RotaryEncoderController rotEncCx;
Encoder ENC1;
Encoder ENC2;
RotaryEncoderSupervisor rSup;

void setup() {
	Serial.begin(9600);
	ENC1.OnSetup(9,8);			// CLK = 9  DT = 8
	rotEncCx.OnSetup(&ENC1);
	rSup.OnSetup(5,4,6);
  }

void loop() {
   rotEncCx.resolveEncoder(gcp,gcd,&ENC1,rSup);
}
