#include "RotaryEncoder.hpp"

Encoder::Encoder()
:	
CLK(0),
DT(0)

{
	//Serial.print("\n\n ... EncoderInitialized ...\n");
}

void Encoder::OnSetup(int clock_pin, int detector_pin) {
   this->CLK = clock_pin;
   this->DT = detector_pin;
}

RotaryEncoderController::RotaryEncoderController()
:	
value(0),
rotation(0),
RotPosition(0),
LeftRight(0)

{
	//Serial.print("\n\n ... RotaryEncoderController Initialized ...\n");
}

void RotaryEncoderController::OnSetup(Encoder * encoder) {
   pinMode (encoder->CLK,INPUT);
   pinMode (encoder->DT,INPUT);
   this->rotation = digitalRead(encoder->CLK);
}

int RotaryEncoderController::resolveEncoder(
	unsigned long global_counter,
	unsigned long global_delay, 
	Encoder * encoder,
	RotaryEncoderSupervisor supervisor) {
	//this->value = digitalRead(encoder.CLK);
	this->value = digitalRead(encoder->CLK);
	//Serial.println(rotary_encoder_controller->RotPosition);
	if (this->value != this->rotation){ //DT pin determines direction of rotation
		if (digitalRead(encoder->DT) != this->value) {  // Clockwise
		this->RotPosition ++;
		this->LeftRight = true;
		} else { //Counterclockwise
		this->LeftRight = false;
		this->RotPosition--;
		}
	
	supervisor.superviseEncoder(this);
	this->rotation = this->value;
	}
}

RotaryEncoderSupervisor::RotaryEncoderSupervisor()
:	
GreenLed(0),
RedLed(0),
BlueLed(0)

{
	//Serial.print("\n\n ... RotaryEncoderSupervisor Initialized ...\n");
}

void RotaryEncoderSupervisor::OnSetup(
    int green_pin,
    int red_pin,
    int blue_pin) {
    this->GreenLed = green_pin;
    this->RedLed = red_pin;
    this->BlueLed = blue_pin;
   	pinMode (this->GreenLed, OUTPUT);
   	pinMode (this->RedLed, OUTPUT);
   	pinMode (this->BlueLed, OUTPUT);

}

int RotaryEncoderSupervisor::superviseEncoder(
	RotaryEncoderController * rotary_encoder_controller) {
	    if (rotary_encoder_controller->LeftRight) {
	    Serial.println ("clockwise");
		digitalWrite (this->RedLed, HIGH);
		digitalWrite (this->GreenLed, LOW);
	    } else {
	    Serial.println("counterclockwise");
	    digitalWrite (this->RedLed, LOW);
	    digitalWrite (this->GreenLed, HIGH);
	    }
	    Serial.print("Encoder RotPosition: ");
	    Serial.println(rotary_encoder_controller->RotPosition);
}
