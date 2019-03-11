#ifndef __GEAR_HPP__
#define __GEAR_HPP__

#include <Encoder.h>

class Gear
{
public:

    Gear
    (
        int portA,
        int portB,
        int numEncoderTeeth,
        int numCrankTeeth,
        double initialGearRadius,
        double crankRadius,
        double rodLength,
        double ticksPerRev
    );

    double getRadius();
    double getCrankAngle();

    Encoder encoder;
    const double l;
    const double r;
    const double ticksToCrankAngle;
    const double encoderDegreesPerTick;
    const double ticksPerRev;
    const int numEncoderTeeth;
    const int numCrankTeeth;
};

#endif
