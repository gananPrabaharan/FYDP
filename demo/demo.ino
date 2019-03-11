#include <Gear.hpp>
#include <Motor.hpp>

#define ENCODER_TICKS_PER_REVOLUTION (24*4)

#define FRONT_GEAR_A_PORT            (10)
#define FRONT_GEAR_B_PORT            (12)
#define FRONT_GEAR_CRANK_RADIUS      (5.5)
#define FRONT_GEAR_ROD_LENGTH        (5.0)
#define FRONT_GEAR_INITAL_RADIUS     (FRONT_GEAR_CRANK_RADIUS + FRONT_GEAR_ROD_LENGTH)
#define FRONT_GEAR_ENCODER_TEETH     (35)
#define FRONT_GEAR_CRANK_TEETH       (75)


#define E1 (6)
#define M1 (7)
#define E2 (5)
#define M2 (4)

Gear frontGear(
    FRONT_GEAR_A_PORT,
    FRONT_GEAR_B_PORT,
    FRONT_GEAR_ENCODER_TEETH,
    FRONT_GEAR_CRANK_TEETH,
    FRONT_GEAR_INITAL_RADIUS,
    FRONT_GEAR_CRANK_RADIUS,
    FRONT_GEAR_ROD_LENGTH,
    ENCODER_TICKS_PER_REVOLUTION
);

void setup() 
{
    Serial.begin(9600);
    Serial.println("Encoder Demo");
    
//    pinMode(E1,OUTPUT);
//    pinMode(M1,OUTPUT);
//    pinMode(E2,OUTPUT);
//    pinMode(M2,OUTPUT);
}

long value;
long last = -1;
int motor_val = 255;

void loop() 
{
    value = frontGear.encoder.read();
    double frontRadius = frontGear.getRadius();
    double rearRadius;// = rearGear.getRadius();
    
    if (value != last) {
        Serial.println(frontRadius);
        Serial.println(value);
        last = value;
    }
}

    
/*
    if(value > 10.5){
      digitalWrite(M1,HIGH);
      analogWrite(E1,motor_val);
    }
    else{
      digitalWrite(M1,LOW);
      analogWrite(E1,motor_val);
    }


      analogWrite(E1,motor_val);
      digitalWrite(M1,HIGH);
      
      delay(500);
      digitalWrite(E1,LOW);
      
      analogWrite(E1,motor_val);
      digitalWrite(M1,HIGH);
*/
