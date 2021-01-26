#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTimeStamp;
double lastTimeStamp;
double dt;

double motorSpeed = 0;

double constexpr deadzone = 0.05;
//srx
void Robot::RobotInit() {
	xbox = new frc::XboxController(0);

	_talonMotor = new wml::TalonSrx(99);
	_talonMotor->SetInverted(false);
}

void Robot::RobotPeriodic() {}


void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	motorSpeed = xbox->GetTriggerAxis(hand::kLeftHand);
	if (motorSpeed >= deadzone) {
		_talonMotor->Set(0.8);
	} else {
		_talonMotor->Set(0);
	}

	lastTimeStamp = currentTimeStamp;
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}