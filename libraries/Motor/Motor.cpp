#include "Motor.hpp"

Motor::Motor(int portM, int portE) 
: PORT_M(portM), PORT_E(portE)
{
    pinMode(PORT_M, OUTPUT); 
    pinMode(PORT_E, OUTPUT); 
}

void Motor::enable()
{
	digitalWrite(PORT_M, HIGH); 
	analogWrite(PORT_E, LOW);
}

void Motor::disable()
{
	digitalWrite(PORT_M, LOW); 
	analogWrite(PORT_E, LOW);
}

void Motor::setSpeed(int speed)
{
	analogWrite(PORT_E, speed);
}