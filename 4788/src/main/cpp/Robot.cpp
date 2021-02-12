#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time 

double falconSpeed;
double constexpr deadzone = 0.1;

// Robot Logic
void Robot::RobotInit() {
	//init controllers 
	xbox = new frc::XboxController(0);

	//Falcon motor 
	_falcon = new wml::TalonFX{12, 2048};

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
		_falcon->Set(falconSpeed/5);
		std::cout << _falcon->GetEncoderTicks() << std::endl;
	} else {
		_falcon->Set(0);
	}

	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}