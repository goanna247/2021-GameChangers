#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time 

//add other variables here

double falconSpeed;
double const deadzone = 0.1;

// Robot Logic
void Robot::RobotInit() {
	//init controllers 
	xbox = new frc::XboxController(0);

	//Falcon motor 
	_falcon = new wml::TalonFX(4);

	_falcon->SetInverted(false);

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

	falconSpeed = xbox->GetY(hand::kRightHand);
	if (abs(falconSpeed) >= deadzone) {
		_falcon->Set(0.1);
	} else {
		_falcon->Set(0);
	}

	_compressor.Update(dt);
	_solenoid.Update(dt);

	if (_solenoid.IsDone()) _solenoid.Stop();
	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}