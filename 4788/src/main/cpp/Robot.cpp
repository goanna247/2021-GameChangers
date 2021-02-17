#include "Robot.h"

using namespace frc;
using namespace wml;
using namespace wayfinder;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// wayfinder::Path::sSpline spline1;
// wayfinder::Path::sPath path1;

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
	wayfinder::RobotControl::Config wfdConfig = {
		drivetrain,
		false,
		true, 

		//make these all controlmap variables later
		0.3, //P 
		0.001, //I  
		0.024, //D

		8.24, //gearbox reduction, eg. 8.24 rotations = 1 wheel rotation
		0.1524, //whel diameter in meters 
		0.5, // max speed of the robot 
		0.3 //max speed of the robot when turning 
	};
	wayFinder = new WayFinder(wfdConfig);

	// Init paths
	wp.path = wayFinder->buildPath(wp.spline1);


	std::cout << "Robot Init" << std::endl;

	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	// Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	// Inverts one side of our drivetrain
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(true);
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(true);

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	StrategyController::Update(dt);
	NTProvider::Update();
	std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderTicks() << std::endl;
	std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderTicks() << std::endl;

	lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	if (wayFinder->followPath(wp.path, dt, false)) {
		std::cout << "Path Complete" << std::endl;
	} else {
		std::cout << "Following Path" << std::endl;
	}
	// Schedule(std::make_shared<DrivetrainAuto>("drive auto", *drivetrain, *wayFinder, wp));
	// drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));

	lastTimeStamp = currentTimeStamp;
}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(drivetrain->GetDefaultStrategy(), true); // Use manual strategy
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}