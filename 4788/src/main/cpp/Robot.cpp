#include "Robot.h"

using namespace frc;
using namespace wml;
using namespace wayfinder;

double currentTimeStamp;
double lastTimeStamp;
double dt;

wayfinder::RobotControl::Config wfdConfig;
double drive_kp = 0.135,  //0.135
			drive_ki = 0.00457, //0.00457
			drive_kd = -0.0005,   //values being set by shuffleboard, -0.0005

			turn_kp = 0.000075, //0.000075
 			turn_ki = 0.0002545, //0.0002545
			turn_kd = 0.00001; //0.00001

// Robot Logic
void Robot::RobotInit() {

	// Init the controllers
	ControlMap::InitsmartControllerGroup(robotMap.contGroup);

	nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("navXReset").SetDouble(0);
	nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("turnAround").SetDouble(0);

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

		&turn_kp, //P angle   0.00008   0.000075
		&turn_ki, //I angle   0.00007   0.0002545
		&turn_kp, //D angle             0.00001

		6.86, //gearbox reduction, eg. 8.24 rotations = 1 wheel rotation
		0.102, //wheel diameter in meters 
		0.3, // max speed of the robot 
		0.3, //max speed of the robot when turning 
		false
	};
	wayFinder = new WayFinder(wfdConfig);

	wayFinder->setBarStop(wfdConfig, 0.1, true);
	wayFinder->setAanglePrc(5);
	wayFinder->disableAngleSE();
	wayFinder->fix();

	// Init paths
	wp.path1L.name = "startToFirstTarget";
	wp.path1L = wayFinder->buildPath(wp.path1L, 0, 0);

	wp.path2L.name = "FirstTargetToMid";
	wp.path2L = wayFinder->buildPath(wp.path2L, 0, 0);

	wp.path3L.name = "MidToSecondTarget";
	wp.path3L = wayFinder->buildPath(wp.path3L, 0, 0);

	wp.path4L.name = "SecondTargetToMid";
	wp.path4L = wayFinder->buildPath(wp.path4L, 0, 0);

	std::cout << "Robot Init" << std::endl;

	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	// robotMap.driveSystem.gyro.Reset();

	// Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	// Inverts one side of our drivetrain
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(false);
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(true);


	// Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	// std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderRotations() << std::endl;
	// std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderRotations() << std::endl;
	// std::cout << "gyro value: " << 	robotMap.driveSystem.gyro.GetAngle() << std::endl;

	//pid values controlled by shuffleboard
	drive_kp = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Drive_P").GetDouble(0);
	// std::cout << "P value: " << drive_kp << std::endl;
	drive_ki = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Drive_I").GetDouble(0);
	// std::cout << "I value: " << drive_ki << std::endl;
	drive_kd = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Drive_D").GetDouble(0);
	// std::cout << "D value: " << drive_kd << std::endl;

	turn_kp = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Turn_P").GetDouble(0);
	// std::cout << "P turn value: " << turn_kp << std::endl;
	turn_ki = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Turn_I").GetDouble(0);
	// std::cout << "I turn value: " << turn_ki << std::endl;
	turn_kd = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Turn_D").GetDouble(0);
	// std::cout << "D turn value: " << turn_kd << std::endl;

	nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Current angle").SetDouble(robotMap.driveSystem.gyro.GetAngle());

	nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Distance to target").SetDouble(wayFinder->getCurrentLocation(wfdConfig, true));

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
	wayFinder->resetLoop();

	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	Schedule(std::make_shared<DrivetrainAuto>("drive auto", *drivetrain, *wayFinder, wp), true);
}

void Robot::AutonomousPeriodic() {
	// std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderRotations() << std::endl;
	// std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderRotations() << std::endl;

	// std::cout << "Gyroscope yaw: " << robotMap.driveSystem.gyro.GetAngle() << std::endl; 

	// wayFinder->followPath(wp.path, dt, false);
}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(drivetrain->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}