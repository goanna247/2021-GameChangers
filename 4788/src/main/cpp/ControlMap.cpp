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

// Falcon
const int ControlMap::falconPort = 99;

// ------------------ Controls ------------------

//falcon 
const tAxis ControlMap::FalconOn{ CoDriver, XboxController::kRightYAxis };
const tButton ControlMap::EncoderRead{ CoDriver, XboxController::kX };
