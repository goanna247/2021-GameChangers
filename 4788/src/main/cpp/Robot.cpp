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

	climber = new Climber(robotMap.climberSystem.climberMotor);
	climber->SetDefault(std::make_shared<ClimberStrategy>("Climber Manual", *climber, robotMap.contGroup));
	StrategyController::Register(climber);

	intake = new Intake(robotMap.intakeSystem.intakeMotor);
	intake->SetDefault(std::make_shared<IntakeStrategy>("Intake manual", *intake, robotMap.contGroup));
	StrategyController::Register(intake);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	// Update our controllers and strategy
	StrategyController::Update(dt);
	climber->update(dt);
	intake->update(dt);
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
	Schedule(climber->GetDefaultStrategy(), true);
	Schedule(intake->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}