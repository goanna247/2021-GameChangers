#include "Robot.h"

using namespace frc;
using namespace wml;
using namespace wayfinder;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logic
void Robot::RobotInit() {

	// Init the controllers
	ControlMap::InitsmartControllerGroup(robotMap.contGroup);

	auto camera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera.SetFPS(30);
	camera.SetResolution(160, 120);

	auto camera2 = CameraServer::GetInstance()->StartAutomaticCapture(1);
	camera2.SetFPS(30);
	camera2.SetResolution(160, 120);

	// Create wml drivetrain
	drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);
	wayFinder = new WayFinder(&robotMap.driveSystem.wfdConfig);

	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	// Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	// Inverts one side of our drivetrain
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(true);
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(false);

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);



}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	StrategyController::Update(dt);
	NTProvider::Update();

	lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {
	Schedule(std::make_shared<DrivetrainAuto>("drive auto", *drivetrain, *wayFinder, *wp));
	// std::cout << wayFinder->getCurrentLocation(&robotMap.driveSystem.wfdConfig, true);
}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(drivetrain->GetDefaultStrategy(), true); // Use manual strategy
}
void Robot::TeleopPeriodic() {
	// std::cout << robotMap.driveSystem.FL.Encoder.GetEncoderTicks() << std::endl;
	// std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderTicks() << std::endl;
	// std::cout << "Encoder RIGHT: " << robotMap.driveSystem.FR.GetEncoderTicks() << std::endl;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}