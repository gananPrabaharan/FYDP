#include "Motor.hpp"
#include <Arduino.h>

Motor::Motor(int portM, int portE) 
: PORT_M(portM), PORT_E(portE)
{
    pinMode(PORT_M, OUTPUT); 
    pinMode(PORT_E, OUTPUT); 
}

void Motor::stop()
{
	analogWrite(PORT_E, LOW);
}

void Motor::setSpeed(int speed, Direction direction)
{
    stop();
    digitalWrite(PORT_M, (direction == CLOCKWISE) ? HIGH : LOW);
	analogWrite(PORT_E, speed);
}
