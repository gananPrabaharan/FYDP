#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__

class Motor
{
    
public:

    enum Direction {
        CLOCKWISE,
        COUNTERCLOCKWISE,
        CW = CLOCKWISE,
        CCW = COUNTERCLOCKWISE
    };

	Motor(int portM, int portE);

	void stop();
	void setSpeed(int speed, Direction direction);

private:
	const int PORT_M;
	const int PORT_E;
};

#endif
