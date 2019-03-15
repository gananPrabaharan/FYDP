#include "Button.hpp"
#include <Arduino.h>

Button::Button(int port, void (*onPress)(int state)) 
: port(port), onPress(onPress)
{
    pinMode(port, INPUT);
}

void Button::loop_iteration()
{
    int readValue = digitalRead(port);  // read input value
    
    if (readValue != lastReadValue) {
        // reset the debouncing timer
        lastDebounceTime = millis();
    }

    //filter out any noise by setting a time buffer
    if (readValue != state) {
        if (millis() - lastDebounceTime > DEBOUNCE_DELAY) {
            state = readValue;
            onPress(state);
        }
    }
    lastReadValue = readValue;
}
