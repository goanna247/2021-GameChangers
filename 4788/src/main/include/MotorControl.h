#include "RobotMap.h"

// Left SRX 9, spx 2
// Right SRX 

class MotorControl {
 public:
	void update(double dt);
	void idleUpdate();

 private:
	// Private Methods
	double PID(double goal, double dt, double input);

	// Private variables/instances
	wml::TalonSrx leftSRX{2, 2048};
	wml::VictorSpx leftSPX{9};

	wml::actuators::MotorVoltageController leftMotors = wml::actuators::MotorVoltageController::Group(leftSRX, leftSPX);
	wml::Gearbox leftGearbox{&leftMotors, &leftSRX};
};