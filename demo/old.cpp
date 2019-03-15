
// octowio

//Button button(BUTTON_PORT, &onButtonPress);
//
//void onButtonPress(int state)
//{
//    Serial.println(state);
//    
//    if (state == LOW) {
//
//        digitalWrite(LED_BUILTIN, LOW); 
//        Serial.println("MOTOR STOP");
//        motor.stop();
//        direction = !direction;
//        if (direction == 1) {
//            Serial.println("NEXT: CLOCKWISE");
//        } else {
//            Serial.println("NEXT: COUNTERCLOCKWISE");
//        }
//    } else {
//
//        digitalWrite(LED_BUILTIN, HIGH); 
//
//        if (direction == 1) {
//            Serial.println("MOTOR RUN: CLOCKWISE");
//            motor.setSpeed(motor_val, Motor::CLOCKWISE);                    
//        } else {
//            Serial.println("MOTOR_RUN: COUNTERCLOCKWISE");
//            motor.setSpeed(motor_val, Motor::COUNTERCLOCKWISE);
//        }
//    } 
//}

// PRINT THE ENCODER STATUS

//    long readValue = abs(encoder.read());
//    if (readValue != lastReadValue) {
//        Serial.print("Radius: "); Serial.println(getRadius());
//        lastReadValue = readValue;
//    }

// ganapathy

//        //Get number of encoder ticks in displacement for front and rear
//        numEncoderTeethRear;
//        numEncoderTeethFront;
//
////        if (bike.getCadence() > desired
//        if (currentCadence > desiredCadence){
//            // Lower Gear Ratio
//            newRearRadius = rearGear.getRadius() + displacement;
//            newFrontRadius = frontGear.getRadius() - displacement;
//            
//        } else {
//            // Increase Gear Ratio
//            newRearRadius = rearGear.getRadius() - displacement;
//            newFrontRadius = frontGear.getRadius() + displacement;
//        }
//        
//        int remainderRear = numEncoderTeethRear % INCREMENTAL_TEETH_REAR;
//        int remainderFront = numEncoderTeethFront % INCREMENTAL_TEETH_FRONT;
//        
//        int numStepsRear = (numEncoderTeethRear - remainderRear) / INCREMENTAL_TEETH_REAR;
//        int numStepsFront = (numEncoderTeethFront - remainderFront) / INCREMENTAL_TEETH_FRONT;
