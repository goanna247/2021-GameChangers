#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTimeStamp;
double lastTimeStamp;
double dt;

double leftSpeed = 0;
double rightSpeed = 0;

double magSpeed = 0;
double intakeSpeed = 0;
double shooterSpeed = 0;

double constexpr deadzone = 0.05;
//srx
void Robot::RobotInit() {
	xbox = new frc::XboxController(0);
	

	_shooterMotor = new wml::TalonSrx(8);
	_magMotor = new wml::VictorSpx(5);
	_intakeMotor = new wml::VictorSpx(7);
	
	_frontLeft = new wml::TalonSrx(1);
	_backLeft = new wml::TalonSrx(2);

	_frontRight = new wml::TalonSrx(3);
	_backRight = new wml::TalonSrx(4);

	_shooterMotor->SetInverted(false);
	_magMotor->SetInverted(false);
	_intakeMotor->SetInverted(false);

	_frontLeft->SetInverted(false);
	_backLeft->SetInverted(false);
	_frontRight->SetInverted(false);
	_backRight->SetInverted(false);
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

	// leftSpeed = xbox->JoystickHand(hand::kLeftHand);

	shooterSpeed = xbox->GetTriggerAxis(hand::kLeftHand);
	if (shooterSpeed >= deadzone) {
		_shooterMotor->Set(shooterSpeed);
	} else {
		_shooterMotor->Set(0);
	}

	magSpeed = xbox->GetTriggerAxis(hand::kRightHand);
	if (magSpeed >= deadzone) {
		_magMotor->Set(magSpeed);
	} else {
		_magMotor->Set(magSpeed);
	}

	if( xbox->GetYButton()) {
		_intakeMotor->Set(0.5);
	}

	if (fabs(xbox->GetY(hand::kRightHand)) >= deadzone) {
		rightSpeed = xbox->GetY(hand::kRightHand);
	} else {
		rightSpeed = 0;
	}

	if (fabs(xbox->GetY(hand::kLeftHand)) >= deadzone) {
		leftSpeed = xbox->GetY(hand::kLeftHand);
	} else {
		leftSpeed = 0;
	}


	_frontLeft->Set(leftSpeed);
	_backLeft->Set(leftSpeed);

	_frontRight->Set(rightSpeed);
	_backRight->Set(rightSpeed);

	lastTimeStamp = currentTimeStamp;
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}