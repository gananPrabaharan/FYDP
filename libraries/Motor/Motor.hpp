#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__

class Motor
{
public:

	Motor(int portM, int portE);

	void enable();
	void disable();
	void setSpeed(int speed);

private:
	const int PORT_M;
	const int PORT_E;
};

#endif