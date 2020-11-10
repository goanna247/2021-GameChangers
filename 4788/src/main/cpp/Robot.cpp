#include "Robot.h"

using namespace wml;
using namespace wml::controllers; // Because Yeet

XboxController xbox{ 0 };

// Drivetrain
SparkMax FL{ 12, SparkMax::MotorType::kNEO, 42 };
SparkMax BL{ 13, SparkMax::MotorType::kNEO, 42 };
SparkMax FR{ 10, SparkMax::MotorType::kNEO, 42 };
SparkMax BR{ 11, SparkMax::MotorType::kNEO, 42 };

actuators::MotorVoltageController leftMotors = actuators::MotorVoltageController::Group(FL, BL);
actuators::MotorVoltageController rightMotors = actuators::MotorVoltageController::Group(FR, BR);

Gearbox leftGearbox{ &leftMotors, &FL, 8.45 };
Gearbox rightGearbox{ &rightMotors, &FR, 8.45 };

DrivetrainConfig drivetrainConfig{ leftGearbox, rightGearbox };
Drivetrain drivetrain{ drivetrainConfig };
actuators::DoubleSolenoid changeGears{ 1, 0, 1, 0 };

// Turret
TalonSrx TurretRotation{ 23, 2048 };
actuators::MotorVoltageController rotationMotors = actuators::MotorVoltageController::Group(TurretRotation);
Gearbox turretRotation{ &rotationMotors, &TurretRotation, 0 };

TalonSrx TurretAngle{ 20 };
actuators::MotorVoltageController angleMotors = actuators::MotorVoltageController::Group(TurretAngle);
Gearbox turretAngle{ &angleMotors };

TalonSrx FlyWheel1{ 22 };
TalonSrx FlyWheel2{ 21 };
actuators::MotorVoltageController flyWheelMotors = actuators::MotorVoltageController::Group(FlyWheel1, FlyWheel2);
Gearbox FlyWheel{ &flyWheelMotors };


// Intake
TalonSrx IntakeMotor{24, 2048 };
actuators::MotorVoltageController IntakeMotors = actuators::MotorVoltageController::Group(IntakeMotor);
Gearbox Intake{ &IntakeMotors, &IntakeMotor, 8.45 };
actuators::DoubleSolenoid IntakeSolenoid{ 1, 6, 7, 0 };

// Magazine
TalonSrx MagMotor{ 25, 2048 };
actuators::MotorVoltageController MagMotors = actuators::MotorVoltageController::Group(MagMotor);
Gearbox Mag{&MagMotors, &MagMotor, 8.45};

bool intakeToggle = false;
bool speedToggle = false;

// Robot Logic
void Robot::RobotInit() {
	rightGearbox.transmission->SetInverted(true);
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

	// Driving/Turret
	double leftSpeed=0, rightSpeed=0, rotationSpeed=0, angleSpeed=0, flyeWheelSpeed=0, magSpeed=0, intakeSpeed=0;
	double maxSpeed = 0.3;
	if (xbox.GetAxis(XboxController::kLeftThrottle) > 0.15) {


		// Turret
		rotationSpeed = fabs(xbox.GetAxis(XboxController::kRightXAxis)) > 0.1 ? xbox.GetAxis(XboxController::kRightXAxis) : 0;
		angleSpeed = fabs(xbox.GetAxis(XboxController::kLeftYAxis)) > 0.1 ? xbox.GetAxis(XboxController::kLeftYAxis) : 0;
		flyeWheelSpeed = xbox.GetAxis(XboxController::kRightThrottle) > 0.15 ? -xbox.GetAxis(XboxController::kRightThrottle) : 0;

	} else {


		// Driving
		if (fabs(xbox.GetAxis(XboxController::kLeftYAxis)) > 0.1) {
			leftSpeed = xbox.GetAxis(XboxController::kLeftYAxis);
			leftSpeed = -(fabs(leftSpeed)*leftSpeed);
		} else {leftSpeed = 0;}

		if (fabs(xbox.GetAxis(XboxController::kRightYAxis)) > 0.1) {
			rightSpeed = xbox.GetAxis(XboxController::kRightYAxis);
			rightSpeed = -(fabs(rightSpeed)*rightSpeed);
		} else {rightSpeed = 0;}

		if (xbox.GetButton(XboxController::kBumperLeft)) {
			changeGears.SetTarget(actuators::BinaryActuatorState::kForward);
		} else {
			changeGears.SetTarget(actuators::BinaryActuatorState::kReverse);
		}	
	}

	// Intake
	if (xbox.GetButton(XboxController::kY)) {
		IntakeSolenoid.SetTarget(actuators::BinaryActuatorState::kForward);
		intakeSpeed = 0.3;
	} else {
		IntakeSolenoid.SetTarget(actuators::BinaryActuatorState::kReverse);
		intakeSpeed = 0;
	}

	// Magazine
	if (xbox.GetButton(XboxController::kA)) {
		magSpeed = 1;
	} else {
		magSpeed = 0;
	}

	if (xbox.GetButton(XboxController::kBumperRight)) {
		maxSpeed = 1;
	} else {
		maxSpeed = 0.3;
	}

	rotationSpeed *= 0.3;
	angleSpeed *= 0.3;

	leftSpeed *= maxSpeed;
	rightSpeed *= maxSpeed;

	changeGears.Update(0);
	IntakeSolenoid.Update(0);
	// drivetrain.Set(leftSpeed, rightSpeed);
	leftGearbox.transmission->SetVoltage(12 * leftSpeed);
	rightGearbox.transmission->SetVoltage(12 * rightSpeed);

	turretRotation.transmission->SetVoltage(12 * -rotationSpeed);
	turretAngle.transmission->SetVoltage(12 * -angleSpeed);
	FlyWheel.transmission->SetVoltage(12 * flyeWheelSpeed);
	Mag.transmission->SetVoltage(12 * magSpeed);
	Intake.transmission->SetVoltage(12 * intakeSpeed);
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}