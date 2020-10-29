#include "RobotMap.h"

class MotorControl {
 public:
	void update();

 private:

	void PID(double goal, double dt, double input);
};