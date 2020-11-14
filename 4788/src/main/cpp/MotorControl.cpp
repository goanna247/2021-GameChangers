#include "MotorControl.h"

wml::controllers::XboxController xbox{ 0 };

double kP = 0.5;
double kI = 0.0001;
double kD = 0.02;

double previousError = 0;


double leftPower = 0;
double rightPower = 0.2;
double encoder = 0;

double MotorControl::PID(double goal, double dt, double input) {
	double error = goal - input;
	double derror = (error - previousError)/dt;

	double sum = sum + error * dt;

	double output = kP * error + kI * sum + kD * derror;

	return output;
}


void MotorControl::idleUpdate() {

	// std::cout << "right encoder rotations " << rightSRX.GetEncoderRotations() << std::endl;
	// std::cout << "right power" << rightPower << std::endl;
	// std::cout << "Encoder: " << encoder << std::endl;
	// std::cout << "LeftPower: " << leftPower << std::endl;
}


void MotorControl::update(double dt) {
	double deadZone = 0.15;


	if (abs(xbox.GetAxis(wml::controllers::XboxControllers::kRightYAxis)) > deadZone) {
		rightPower = xbox.GetAxis(wml::controllers::XboxControllers::kRightYAxis);
	} else {
		rightPower = 0;
	}
	

	rightSRX.Set(rightPower);
	rightSPX.Set(rightPower);
}