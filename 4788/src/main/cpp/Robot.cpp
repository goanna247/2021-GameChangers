#include "Robot.h"

using namespace frc;
using namespace wml;
using namespace wayfinder;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// wayfinder::Path::sSpline spline1;
// wayfinder::Path::sPath path1;

wayfinder::RobotControl::Config wfdConfig;

// double drive_kp = 0.3,
// 				drive_ki = 0,
// 				drive_kd = 0,

// 				turn_kp = 0.000002,
// 				turn_ki = 0,
// 				turn_kd = 0;



				// double drive_kp = 0.2,
				// drive_ki = 0.0000001,
				// drive_kd = -0.0006,

				// turn_kp = 0.00002,
				// turn_ki = 0.0000001,
				// turn_kd = -0.00009;

				double drive_kp = 0.2,
				drive_ki = 0.001,
				drive_kd = -0.0005,

				turn_kp = 0.0005,
				turn_ki = 0.00025,
				turn_kd = -0.0005;

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
	wfdConfig = {
		drivetrain,
		false,
		true,

		//make these all controlmap variables later
		&drive_kp, //P drive
		&drive_ki, //I drive
		&drive_kd, //D drive

		&turn_kp, //P angle
		&turn_ki, //I angle 
		&turn_kp, //D angle

		8.24, //gearbox reduction, eg. 8.24 rotations = 1 wheel rotation
		0.1524, //wheel diameter in meters 
		0.5, // max speed of the robot 
		0.5 //max speed of the robot when turning 
	};
	wayFinder = new WayFinder(wfdConfig);

	// Init paths
	wayFinder->setStepSize(0.005f);
	wp.path = wayFinder->buildPath(wp.spline1);


	std::cout << "Robot Init" << std::endl;

	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	// Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	// Inverts one side of our drivetrain
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(false);
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(false);

	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	// std::cout << "Current Location: " << wayFinder->getCurrentLocation(wfdConfig, true) << std::endl;
	std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderRotations() << std::endl;
	std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderRotations() << std::endl;

	// std::cout << "Current Location M: " << wayFinder->getCurrentLocation(wfdConfig, true) << std::endl;
	// std::cout << "Current Angle: " << robotMap.driveSystem.gyro.GetAngle() << std::endl;
	StrategyController::Update(dt);
	NTProvider::Update();

	lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {


	robotMap.driveSystem.gyro.Reset();
	// drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));

	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	Schedule(std::make_shared<DrivetrainAuto>("drive auto", *drivetrain, *wayFinder, wp), true);
}
void Robot::AutonomousPeriodic() {

	// if (wayFinder->followPath(wp.path, dt, false)) {
	// 	std::cout << "Path Complete" << std::endl;
	// } else {
	// 	std::cout << "Following Path" << std::endl;

	// 	// std::cout << "Rotations to target: " << wayFinder->getRotationsToTarget_STATIC(wp.path, wfdConfig) << std::endl;
	// 	std::cout << "Path length: " << wp.path.pathLength << std::endl;
	// 	std::cout << "Current Location M: " << wayFinder->getCurrentLocation(wfdConfig, true) << std::endl;

	// 	std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderRotations() << std::endl;
	// 	std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderRotations() << std::endl;

	// 	std::cout << "Gyroscope yaw: " << robotMap.driveSystem.gyro.GetAngle() << std::endl; 
	// }

	std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderRotations() << std::endl;
	std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderRotations() << std::endl;

	std::cout << "Gyroscope yaw: " << robotMap.driveSystem.gyro.GetAngle() << std::endl; 


	// wayFinder->testDrivePID(dt, wfdConfig);

	// lastTimeStamp = currentTimeStamp;
}


// Manual Robot Logic
void Robot::TeleopInit() {
	// Schedule(drivetrain->GetDefaultStrategy(), true); // Use manual strategy
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}