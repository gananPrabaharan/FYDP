#include "Motor.hpp"
#include "Button.hpp"
#include "Gear.hpp"
#include "Bike.hpp"

#define FRONT_ENCODER_A_PORT            (12)
#define FRONT_ENCODER_B_PORT            (13)
#define FRONT_ENCODER_GEAR_TEETH        (35)
#define FRONT_ENCODER_TICKS_PER_REV     (24*4)
#define FRONT_CRANK_GEAR_RADIUS         (5.0)
#define FRONT_CRANK_GEAR_TEETH          (75)    
#define FRONT_ROD_LENGTH                (5.5)
#define FRONT_INITAL_RADIUS             (FRONT_CRANK_GEAR_RADIUS + FRONT_ROD_LENGTH)
#define FRONT_MOTOR_PORT_M              (10)
#define FRONT_MOTOR_PORT_E              (11)
#define FRONT_MOTOR_EXPANSION_DIRECTION (Motor::CLOCKWISE)

// TODODOODODODODODO
#define REAR_ENCODER_A_PORT            (12)
#define REAR_ENCODER_B_PORT            (13)
#define REAR_ENCODER_GEAR_TEETH        (35)
#define REAR_ENCODER_TICKS_PER_REV     (24*4)
#define REAR_CRANK_GEAR_RADIUS         (5.0)
#define REAR_CRANK_GEAR_TEETH          (75)    
#define REAR_ROD_LENGTH                (5.5)
#define REAR_INITAL_RADIUS             (FRONT_CRANK_GEAR_RADIUS + FRONT_ROD_LENGTH)
#define REAR_MOTOR_PORT_M              (10)
#define REAR_MOTOR_PORT_E              (11)
#define REAR_MOTOR_EXPANSION_DIRECTION (Motor::COUNTERCLOCKWISE)

//TODO
double desiredCadence;

Gear frontGear(
    FRONT_ENCODER_A_PORT,
    FRONT_ENCODER_B_PORT,
    FRONT_ENCODER_GEAR_TEETH,
    FRONT_ENCODER_TICKS_PER_REV,
    FRONT_CRANK_GEAR_TEETH,
    FRONT_CRANK_GEAR_RADIUS,
    FRONT_ROD_LENGTH,
    FRONT_INITAL_RADIUS,
    FRONT_MOTOR_PORT_M,
    FRONT_MOTOR_PORT_E,
    FRONT_MOTOR_EXPANSION_DIRECTION
);

Gear rearGear(
    REAR_ENCODER_A_PORT,
    REAR_ENCODER_B_PORT,
    REAR_ENCODER_GEAR_TEETH,
    REAR_ENCODER_TICKS_PER_REV,
    REAR_CRANK_GEAR_TEETH,
    REAR_CRANK_GEAR_RADIUS,
    REAR_ROD_LENGTH,
    REAR_INITAL_RADIUS,
    REAR_MOTOR_PORT_M,
    REAR_MOTOR_PORT_E,
    REAR_MOTOR_EXPANSION_DIRECTION
);

Bike bike(frontGear, rearGear);

void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT); 
    Serial.begin(9600); 
}

void loop()
{
    // from serial
    double desiredCadence;

    if (bike.getCadence() != desiredCadence) {
        bike.setTargetCadence(desiredCadence);
    }

    frontGear.loopIteration();
    rearGear.loopIteration();
}
