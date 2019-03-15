#ifndef __GEAR_HPP__
#define __GEAR_HPP__

#include <Encoder.h>
#include "Motor.hpp"

class Gear
{
public:

    static const int MOTOR_SPEED;

    Gear
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
    );

    void setTargetRadius(double targetRadius);
    double getRadius();
    void loopIteration();

    const double MAX_RADIUS;
    const double MIN_RADIUS;

private:

    Encoder encoder;
    Motor motor;
    Motor::Direction expand;
    Motor::Direction contract;
    
    const double l;
    const double r;
    const double ticksToCrankAngle;
    long lastReadValue;
    double targetRadius;

    double getCrankAngle();
};

#endif
