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
double drive_kp = 0.3,
			drive_ki = 0.0000001,
			drive_kd = 0.0000001,

			turn_kp = 0.000000001, //values being set by shuffleboard 
 			turn_ki = 0.000000001,
			turn_kd = 0.000000001;
//past values: 
//-0.00001; // -0.000015;  -0.6

wayfinder::PIDTuner *tuner;

// Robot Logic
void Robot::RobotInit() {

	// Init the controllers
	ControlMap::InitsmartControllerGroup(robotMap.contGroup);

	nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("navXReset").SetDouble(0);

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

		6.86, //gearbox reduction, eg. 8.24 rotations = 1 wheel rotation
		0.102, //wheel diameter in meters 
		1, // max speed of the robot 
		1 //max speed of the robot when turning 
	};
	wayFinder = new WayFinder(wfdConfig);

	// Init paths
	wayFinder->setStepSize(0.005f);
	wp.path = wayFinder->buildPath(wp.spline1);

	std::cout << "Robot Init" << std::endl;

	// Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	robotMap.driveSystem.gyro.Reset();

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

	std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderRotations() << std::endl;
	std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderRotations() << std::endl;

	//pid values controlled by shuffleboard
	turn_kp = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Turn_P").GetDouble(0);
	std::cout << "P value: " << turn_kp << std::endl;
	turn_ki = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Turn_I").GetDouble(0);
	std::cout << "I value: " << turn_ki << std::endl;
	turn_kd = nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Turn_D").GetDouble(0);
	std::cout << "D value: " << turn_kd << std::endl;

	nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("Current angle").SetDouble(robotMap.driveSystem.gyro.GetAngle());
	std::cout << "Current Angle: " << robotMap.driveSystem.gyro.GetAngle() << std::endl; //0.000185       0.000000001    0.000075

	//reset the navX
	if (nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("navXReset").GetDouble(0) > 0) {
		robotMap.driveSystem.gyro.Reset();
		std::cout << "Reseting" << std::endl;
	}

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

	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	Schedule(std::make_shared<DrivetrainAuto>("drive auto", *drivetrain, *wayFinder, wp), true);
}

void Robot::AutonomousPeriodic() {
	std::cout << "Encoder Left: " << robotMap.driveSystem.FL.GetEncoderRotations() << std::endl;
	std::cout << "Encoder Right: " << robotMap.driveSystem.FR.GetEncoderRotations() << std::endl;

	std::cout << "Gyroscope yaw: " << robotMap.driveSystem.gyro.GetAngle() << std::endl; 
}

// Manual Robot Logic
void Robot::TeleopInit() {
	// Schedule(drivetrain->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}