/*

Name:   		fnc3()
Purpose:		.
				.
				Generate a simple print statement to serial.
*/

#include "Hbridge.hpp"


Hbridgeclass::Hbridgeclass()
		:
 		direction0(0),
 		direction1(0),
 		motor_speed(0),
 	    motor_pwm_pin_number(0)

	{
      //  delay(10);
		//Serial.print("\n\n\n...... Attempting Hbridge initialization ........\n");
        //delay(10);
	}

        void Hbridgeclass::resolveMotorParameters(int dir, int spd, int in1, int in2)
        {
            //  RESOLVE DIRECTION
            direction0 = dir;
            if (direction0 == 0) {
                digitalWrite(in1, HIGH);
                digitalWrite(in2, LOW);
                if (direction0 != direction1)
                direction1 = dir;
            }

            if (direction0 == 1) {
                digitalWrite(in1, LOW);
                digitalWrite(in2, HIGH);
                if (direction0 != direction1)
                direction1 = dir;
            }

            //  RESOLVE SPEED
            motor_speed = spd;
            analogWrite(motor_pwm_pin_number, motor_speed);
        }
