#include "Gear.h"
#include "Math.h"

Gear::Gear
(
    int portA,
    int portB,
    int numEncoderTeeth,
    int numCrankTeeth,
    double initialGearRadius,
    double crankRadius,
    double rodLength,
    double ticksPerRev
) : 
    encoder(portA, portB),
    l(rodLength),
    r(crankRadius),
    ticksToCrankAngle(2*PI / ticksPerRev * numEncoderTeeth / numCrankTeeth)
{ }
    
double Gear::getRadius()
{
    const double max_length = r + l;
    const double theta = getCrankAngle();
    const double cos_theta = cos(theta);
    const double cos_phi = sqrt(1 - (r/l * sin(theta)));
    const double slider_displacement = l * (1 - cos_phi) + r * (1 - cos_theta);
    return max_length - slider_displacement;
}

double Gear::getCrankAngle()
{
    const long ticks = abs(encoder.read());
    return ticks * ticksToCrankAngle;
}
