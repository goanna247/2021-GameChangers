#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logic
void Robot::RobotInit() {
	// Init the controllers
	ControlMap::InitsmartControllerGroup(robotMap.contGroup);

	falcon = new Falcon(robotMap.falconSystem.falconMotor);
	falcon->SetDefault(std::make_shared<FalconStrategy>("Falcon Manual ", *falcon, robotMap.contGroup));
	StrategyController::Register(falcon);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	// Update our controllers and strategy
	StrategyController::Update(dt);
	falcon->update(dt);
	NTProvider::Update();

	lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(falcon->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}