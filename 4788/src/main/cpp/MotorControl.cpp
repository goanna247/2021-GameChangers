#include "MotorControl.h"

wml::controllers::XboxController xbox{ 0 };

double kP = 0.8;
double kI = 2;
double kD = 0.02;

double previousError = 0;


double leftPower = 0;
double encoder = 0;

double MotorControl::PID(double goal, double dt, double input) {
	double error = goal - input;
	double derror = (error - previousError)/dt;

	double sum = sum + error * dt;

	double output = kP * error + kI * sum + kD * derror;

	return output;
}


void MotorControl::idleUpdate() {
	std::cout << "Encoder: " << encoder << std::endl;
	std::cout << "LeftPower: " << leftPower << std::endl;
}


void MotorControl::update(double dt) {
	// put your logic code here
	encoder = leftGearbox.encoder->GetEncoderRotations();

	leftPower = PID(1.5, dt, encoder);


	leftPower += abs(xbox.GetAxis(wml::controllers::XboxController::kLeftYAxis)) > 0.15 ? xbox.GetAxis(wml::controllers::XboxController::kLeftYAxis) : 0;

	leftGearbox.transmission->SetVoltage(12 * leftPower);
}