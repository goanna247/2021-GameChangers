#pragma once

#include <iostream>

#include <frc/Timer.h>
#include <frc/TimedRobot.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Spark.h>
#include <frc/DoubleSolenoid.h>
#include <frc/GenericHID.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTableInstance.h>

#include "strategy/StrategyController.h"
#include "strategy/MPStrategy.h"
#include "NTProvider.h"
#include "WMLCtre.h"
#include "controllers/Controllers.h"
#include "Gearbox.h"
#include "actuators/BinaryServo.h"
#include "actuators/Compressor.h"
#include "actuators/DoubleSolenoid.h"
#include "actuators/VoltageController.h"
#include "sensors/Encoder.h"
#include "sensors/LimitSwitch.h"
#include "sensors/NavX.h"
#include "sensors/PressureSensor.h"

#include <cameraserver/CameraServer.h>
#include <frc/DriverStation.h> 

#include "Toggle.h"

class Robot : public frc::TimedRobot {
 public:
	void RobotInit() override;
	void RobotPeriodic() override;

	void DisabledInit() override;
	void DisabledPeriodic() override;

	void AutonomousInit() override;
	void AutonomousPeriodic() override;

	void TeleopInit() override;
	void TeleopPeriodic() override;

	void TestInit() override;
	void TestPeriodic() override;

	//controllers
	frc::XboxController *driver;
	frc::XboxController *coDriver;

 private:
	//we are just going to assume all the motors are victors 
	wml::VictorSpx _leftMotor1;
	wml::VictorSpx _leftMotor2;
	wml::VictorSpx _leftMotor3;
	wml::VictorSpx _rightMotor1;
	wml::VictorSpx _rightMotor2;
	wml::VictorSpx _rightMotor3;

	//pneumatics stuff, cant remember if we have neumatics so im going to keep this 
	wml::actuators::Compressor _compressor{};
	wml::actuators::DoubleSolenoid _solenoid{0, 1, 0.2};
};
