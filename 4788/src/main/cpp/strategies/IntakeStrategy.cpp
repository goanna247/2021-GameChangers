#include "strategies/IntakeStrategy.h"

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void IntakeManualStrategy::OnUpdate(double dt) {
	double IntakePower = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;

	if (_contGroup.Get(ControlMap::Outake)) { //check if the reverse button is being pushed 
		IntakePower = ControlMap::OutakeSpeed;
	} 
	//i dont think i need an else because if the button isnt pressed itll just be set to the trigger input 

	if (_contGroup.Get(ControlMap::IntakeActuation, wml::controllers::Controller::ButtonMode::ONRISE)) {
		if (!(ControlMap::IntakeToggle)) {
			ControlMap::IntakeToggle = true;
		} else {
			ControlMap::IntakeToggle = false;
		}
	}

	if (!(ControlMap::IntakeToggle)) {
		_intake.setIntake(IntakeStates::DEPLOYED, IntakePower);
	} else {
		_intake.setIntake(IntakeStates::STOWED, 0);
	}
}
