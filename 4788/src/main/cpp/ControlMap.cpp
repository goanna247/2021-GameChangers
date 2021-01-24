#include "ControlMap.h"

using namespace wml;
using namespace wml::controllers;

void ControlMap::InitsmartControllerGroup(SmartControllerGroup &contGroup) {
	// Remap Here (map POV buttons to names etc)
}


// ------------------ Values ------------------


// Controller Ports
const int ControlMap::Xbox1Port = 0;
const int ControlMap::Xbox2Port = 1;

// Deadzones
const double ControlMap::XboxDeadzone = 0.1;
const double ControlMap::TriggerDeadzone = 0.15;

// PCMs
const int ControlMap::PCModule = 1;

// Left Drive
const int ControlMap::FLport = 12;
const int ControlMap::BLport = 13;

// Right Drive
const int ControlMap::FRport = 10;
const int ControlMap::BRport = 11;

// Drivetrain speed
const double ControlMap::MaxDrivetrainSpeed = 0.8;

// Robot Values
const double ControlMap::TrackWidth = 0.56;
const double ControlMap::TrackDepth = 0.60;
const double ControlMap::WheelRadius = 0.0762; // In meters
const double ControlMap::Mass = 50; // KG's

// Intake
const int ControlMap::intakePort = 99;
const int ControlMap::intakeSolenoidPort1 = 99;
const int ControlMap::intakeSolenoidPort2 = 99;
const int ControlMap::intakeEncoderTicks = 2048;
const double ControlMap::IntakeAutoSpeed = 0.3;

// Falcon
const int ControlMap::falconPort = 99;

// ------------------ Controls ------------------

//drivetrain 
const tAxis ControlMap::DrivetrainLeft{ Driver, XboxController::kLeftYAxis };
const tAxis ControlMap::DrivetrainRight{ Driver, XboxController::kRightYAxis };

// Intake
const tAxis ControlMap::Intake{ CoDriver, XboxController::kRightThrottle };
const tAxis ControlMap::Outake{ CoDriver, XboxController::kLeftThrottle };
const tButton ControlMap::DeployIntake{ CoDriver, XboxController::kA };

//falcon 
const tAxis ControlMap::FalconOn{ CoDriver, XboxController::kRightYAxis };
const tButton ControlMap::EncoderRead{ CoDriver, XboxController::kX };