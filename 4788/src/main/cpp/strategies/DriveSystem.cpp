#include "strategies/DriveSystem.h"

using namespace wml;
using namespace wml::controllers;

DrivetrainManual::DrivetrainManual(std::string name, Drivetrain &drivetrain, SmartControllerGroup &contGroup) : Strategy(name), _drivetrain(drivetrain), _contGroup(contGroup) {
	Requires(&drivetrain);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void DrivetrainManual::OnUpdate(double dt) {
	_leftPower = abs(_contGroup.Get(ControlMap::DrivetrainLeft)) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::DrivetrainLeft) : 0;
	_rightPower = abs(_contGroup.Get(ControlMap::DrivetrainRight)) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::DrivetrainRight) : 0;

	_leftPower *= ControlMap::MaxDrivetrainSpeed;
	_rightPower *= ControlMap::MaxDrivetrainSpeed;

	_drivetrain.Set(-_leftPower, -_rightPower);

	if (_contGroup.Get(ControlMap::RightRound)) {
		_drivetrain.Set(0.5, 0.1);
	}

	if(_contGroup.Get(ControlMap::LeftRound)) {
		_drivetrain.Set(0.1, 0.5);
	}

	if (_contGroup.Get(ControlMap::Straight) > ControlMap::TriggerDeadzone) {
		_drivetrain.Set((_contGroup.Get(ControlMap::Straight)) / 1.3, (_contGroup.Get(ControlMap::Straight)) / 1.3);
	}
}