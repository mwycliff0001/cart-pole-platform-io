/*

Title:   		KnobToMotor4
File Name: 		KnobToMotor()

Date:           4.05.2020


Purpose:		Resolve motor speed and direction by reading an analog signal
                from a potentiometer.
*/

#include "KnobToMotor.hpp"

KnobToMotor::KnobToMotor()
		:	
        k2msg(""),
        motor_speed(0),
		motor_direction(0),
		pot_range(0),
		throttle(0)

		{
			//Serial.print("\n\n\n...... Attempting KnobToMotor initialization ........\n");
		}

        bool KnobToMotor::clockPulse(int pulse, int delay) {
           bool retval = 0; 
           retval = ( pulse % delay == 0 ) ? 1 : 0;
           return retval;
        }

         
        // Maps the position of the poteniometer knob to the motor velocity
        int KnobToMotor::setMotorParams(int * analog_reading) {
            int dkc = 0;  //distance from knob to center position
            dkc = (pot_range/2) - * analog_reading;
            motor_direction = ( dkc < 0 ) ? 1 : 0;
            motor_speed = static_cast<int>( abs(dkc) * throttle );
            // Throttle should be set to one initially.
            // After that, it ought to be tweaked as needed.
            return 0;
        }

        int KnobToMotor::setMotorParams(int option, int * analog_reading) {
            int dkc = 0;
            dkc = (pot_range/2) - * analog_reading;
            if (option==0) {
                motor_speed = 0;
                return 0;
            }
            else if (option==1) {
                motor_direction = ( dkc < 0 ) ? 1 : 0;
                motor_speed = static_cast<int>( abs(dkc) * throttle );
                return 0;
            }
            else if (option==2) {
                motor_direction = 1;
                motor_speed = static_cast<int>( abs(dkc) * throttle );
                return 0;
            }
         }

    
    int KnobToMotor::displayValues(int * analog_reading, bool event)
    {
        if(!event){}
        else {
            
            char s1[] = "ANALOG:  ";
            char s2[] = "    MOTOR SPEED:  ";
            char s3[] = "    DIRECTION:  ";
            char i1[9];
            char i2[9];
            char i3[9];
            itoa (* analog_reading, i1, 10);
            itoa (motor_speed, i2, 10);
            itoa (motor_direction, i3, 10);
            
            strcpy(k2msg, s1);
            strcat(k2msg, i1);
            
            strcat(k2msg, s2);
            strcat(k2msg, i2);
            
            strcat(k2msg, s3);
            strcat(k2msg, i3);
            
            Serial.print(k2msg);
            Serial.print("\n\n");
        }
        return 0;
    }

