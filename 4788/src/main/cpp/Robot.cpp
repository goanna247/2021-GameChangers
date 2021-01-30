#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTimeStamp;
double lastTimeStamp;
double dt;

double motorSpeed = 0;

double leftPower = 0;
double rightPower = 0;

double shooterSpeed = 0;
double magSpeed = 0;
double fireSpeed = 0;
double intakeSpeed = 0;

double constexpr deadzone = 0.05;
//srx
void Robot::RobotInit() {
	xbox = new frc::XboxController(0);

	_shooterMotor = new wml::TalonSrx(1);
	_leftMotor = new wml::TalonSrx(2);
	_rightMotor = new wml::TalonSrx(5);

	_magMotor = new wml::VictorSpx(4);
	_fireMotor = new wml::VictorSpx(8);
	_intakeMotor = new wml::VictorSpx(3);

	_magMotor->SetInverted(false);
	_fireMotor->SetInverted(false);
	_intakeMotor->SetInverted(false);
	_shooterMotor->SetInverted(false);

	_leftMotor->SetInverted(true);
	_rightMotor->SetInverted(false);
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

	shooterSpeed = xbox->GetTriggerAxis(hand::kLeftHand);
	if (shooterSpeed >= deadzone) {
		_shooterMotor->Set(0.8);
	} else {
		_shooterMotor->Set(0);
	}

	magSpeed = xbox->GetTriggerAxis(hand::kRightHand);
	if (magSpeed >= deadzone) {
		_magMotor->Set(1);
	} else {
		_magMotor->Set(0);
	}

	if (xbox->GetAButton()) {
		_intakeMotor->Set(1);
	} else {
		_intakeMotor->Set(0);
	}

	if (xbox->GetYButton()) {
		_fireMotor->Set(1);
	} else {
		_fireMotor->Set(0);
	}

		if (fabs(xbox->GetY(hand::kRightHand)) >= deadzone) {
		rightPower = xbox->GetY(hand::kRightHand);
	} else {
		rightPower = 0;
	}

	if (fabs(xbox->GetY(hand::kLeftHand)) >= deadzone ) {
		leftPower = xbox->GetY(hand::kLeftHand);
	} else {
		leftPower = 0;
	}

	_leftMotor->Set(leftPower);
	
	_rightMotor->Set(rightPower);

	lastTimeStamp = currentTimeStamp;
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}