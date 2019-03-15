#include "Bike.hpp"
#include <Math.h>

Bike::Bike(Gear frontGear, Gear rearGear)
: 
    frontGear(frontGear), 
    rearGear(rearGear),
    MAX_GEAR_RATIO(rearGear.MIN_RADIUS / frontGear.MAX_RADIUS),
    MIN_GEAR_RATIO(rearGear.MAX_RADIUS / frontGear.MIN_RADIUS)
{ }

void Bike::setTargetCadence(double desiredCadence)
{
    double gearRatio = getTargetGearRatio(desiredCadence);
    double displacement = getTargetDisplacement(gearRatio);
    
    frontGear.setTargetRadius(frontGear.getRadius() - displacement);
    rearGear.setTargetRadius(rearGear.getRadius() + displacement);
}

double Bike::getCadence()
{
    //Assume bike_speed is in rpm
    //return getCurrentGearRatio() * bikeSpeed;
    return 0;
}

double Bike::getGearRatio()
{
    return rearGear.getRadius() / frontGear.getRadius();
}

double Bike::getTargetGearRatio(double targetCadence)
{
    // Comes from reed switch
    double currentCadence;// = getCurrentCadence(); 

    double targetGearRatio;
    double currentGearRatio = getGearRatio();
    
    if (currentCadence > 0) {
        targetGearRatio = currentGearRatio * targetCadence / currentCadence;
    } else {
        targetGearRatio = MAX_GEAR_RATIO;
    }
    
    return min(max(targetGearRatio, MIN_GEAR_RATIO), MAX_GEAR_RATIO);
}

double Bike::getTargetDisplacement(double targetGearRatio)
{
    const double frontRadius = frontGear.getRadius();
    const double rearRadius = rearGear.getRadius();
    return (targetGearRatio * frontRadius - rearRadius) / (1 + targetGearRatio);
}
