/*

Name:   		fnc3()
Purpose:		.
				.
				Header file for fnc3.cpp
				To be used in the body of
				main.cpp
*/

#include "Arduino.h"


class Hbridgeclass;
class Hbridgeclass
{
public:
Hbridgeclass();
~Hbridgeclass(){}
void resolveMotorParameters();
void resolveMotorParameters(int dir, int spd, int in1, int in2);

bool direction0;
bool direction1;

int motor_pwm_pin_number;
int motor_speed;

};
