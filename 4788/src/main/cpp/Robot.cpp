#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time 

//variables 
double leftSpeed;
double rightSpeed;
double const deadzone = 0.1;

// Robot Logic
void Robot::RobotInit() {
	//init controllers 
	driver = new frc::XboxController(0);
	coDriver = new frc::XboxController(1);

	//Motors
	_leftMotor1 = new wml::VictorSpx(99);
	_leftMotor2 = new wml::VictorSpx(99);
	_leftMotor3 = new wml::VictorSpx(99);

	_rightMotor1 = new wml::VictorSpx(99);
	_rightMotor2 = new wml::VictorSpx(99);
	_rightMotor3 = new wml::VictorSpx(99);

	_leftMotor1->SetInverted(false);
	_leftMotor2->SetInverted(false);
	_leftMotor3->SetInverted(false);

	_rightMotor1->SetInverted(false);
	_rightMotor2->SetInverted(false);
	_rightMotor3->SetInverted(false);
}

void Robot::RobotPeriodic() {}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
	currentTime = Timer::GetFPGATimestamp();
	dt = currentTime - lastTimeStamp;

	//motor examples
	sparkSpeed = xbox->GetY(hand::kLeftHand);
	_sparkMotor->Set(sparkSpeed);


	talonSpeed = xbox->GetTriggerAxis(hand::kRightHand);
	if (talonSpeed >= deadzone) { //acounts for the deadzone
		_talonMotor->Set(talonSpeed);
	} else {
		_talonMotor->Set(0);
	}

	// ^ the equivilant using a conditional statement 
	//talonSpeed = xbox->GetTriggerAxis(hand::kRightHand) > deadzone ? xbox->GetTriggerAxis(hand::kRightHand) : 0; _talonMotor->Set(talonSpeed);


	leftSpeed = driver->GetTriggeredAxis(hand::kLeftHand);
	if (abs(leftSpeed) >= deadzone) {
		_leftMotor1->Set
	}

	






	if(xbox->GetXButton()) {
		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
	} else {
		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
	}

	_compressor.Update(dt);
	_solenoid.Update(dt);

	if (_solenoid.IsDone()) _solenoid.Stop();
	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}
