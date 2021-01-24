#include "strategies/IntakeStrategies.h"

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {}

void IntakeManualStrategy::OnUpdate(double dt) {
	double powerIn = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
	double powerOut = fabs(_contGroup.Get(ControlMap::Outake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;

	if (_contGroup.Get(ControlMap::DeployIntake, wml::controllers::Controller::ONFALL)) {
		_intake.setIntake(IntakeState::DEPLOYED, powerIn - powerOut);
	} else {
		_intake.setIntake(IntakeState::STOWED);
	}
}