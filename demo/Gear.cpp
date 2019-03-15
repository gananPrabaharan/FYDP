#include "Math.h"
#include "Gear.hpp"
#include <Encoder.h>

const int Gear::MOTOR_SPEED = 50;

Gear::Gear
(
    int encoderPortA,
    int encoderPortB,
    int encoderTeeth,
    double encoderTicksPerRev,
    int crankTeeth,
    double crankRadius,
    double connectingRodLength,
    double initialGearRadius,    
    int motorPortM,
    int motorPortE,
    Motor::Direction expand
) : 
    encoder(encoderPortA, encoderPortB),
    l(connectingRodLength),
    r(crankRadius),
    ticksToCrankAngle(2*PI / encoderTicksPerRev * encoderTeeth / crankTeeth),
    motor(motorPortM, motorPortE),
    expand(expand),
    contract(expand == Motor::CW ? Motor::CCW : Motor::CW),
    MAX_RADIUS(r + l),
    MIN_RADIUS((r+l)/2.0)
{ }

void Gear::setTargetRadius(double targetRadius)
{
    this->targetRadius = targetRadius;
}
    
double Gear::getRadius()
{
    const double theta = getCrankAngle();
    const double cos_theta = cos(theta);
    const double cos_phi = sqrt(1 - (r/l * sin(theta)));
    const double slider_displacement = l * (1 - cos_phi) + r * (1 - cos_theta);
    return MAX_RADIUS - slider_displacement;
}

double Gear::getCrankAngle()
{
    const long ticks = abs(encoder.read());
    return ticks * ticksToCrankAngle;
}

void Gear::loopIteration()
{
    if (targetRadius > getRadius()) {
        motor.setSpeed(MOTOR_SPEED, expand);
    } else {
        motor.setSpeed(MOTOR_SPEED, contract);
    }
}
