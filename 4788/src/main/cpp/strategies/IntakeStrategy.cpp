#include "strategies/IntakeStrategy.h"

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void IntakeManualStrategy::OnUpdate(double dt) {
	powerIn = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
	_intake.setIntake(IntakeStates::DEPLOYED, powerIn);


	// if (powerIn > 0.3) {
	// 	_intake.setIntake(IntakeStates::DEPLOYED, 0.5);
	// } else if (_contGroup.Get(ControlMap::Outake)) {
	// 	_intake.setIntake(IntakeStates::DEPLOYED, -0.5);
	// } else {
	// 	_intake.setIntake(IntakeStates::DEPLOYED, 0);
	// }
	// if (_contGroup.Get(ControlMap::IntakeActuation, wml::controllers::Controller::ONFALL)) {
	// 	_intake.setIntake(IntakeStates::DEPLOYED, powerIn - powerOut);
	// } else {
	// 	_intake.setIntake(IntakeStates::STOWED);
	// }
}
