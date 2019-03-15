#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

class Button
{
public:
    static const int DEBOUNCE_DELAY = 50;

    Button(int port, void (*onPress)(int state));
    void loop_iteration();

    
private:

    const int port;
    int lastReadValue;
    int state;
    unsigned long lastDebounceTime;
    
    void (*onPress)(int state);
      
};

#endif
