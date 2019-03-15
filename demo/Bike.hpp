#ifndef __BIKE_HPP__
#define __BIKE_HPP__

#include "Gear.hpp"

class Bike
{
public:
    Bike(Gear frontGear, Gear rearGear);
    void setTargetCadence(double cadence);
    double getCadence();
    void loopIteration();

private:
    Gear frontGear;
    Gear rearGear;

    const double MAX_GEAR_RATIO;
    const double MIN_GEAR_RATIO;
    
    double getGearRatio();
    double getTargetGearRatio(double targetCadence);
    double getTargetDisplacement(double targetGearRatio);

};

#endif
