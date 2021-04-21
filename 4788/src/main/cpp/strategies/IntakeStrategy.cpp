#include "strategies/IntakeStrategy.h"

/**
 * Intake manual strategy 
 * require the intake class
 */
IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

/**
 * Intake logic 
 * Intake actuation is on a toggle
 * Motor is on the trigger, cant intake both up and down 
 * 
 * toDo @anna make a reverse spin
 */
void IntakeManualStrategy::OnUpdate(double dt) {
	double IntakePower = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;

	if (_contGroup.Get(ControlMap::IntakeActuation, wml::controllers::Controller::ButtonMode::ONRISE)) {
		if (!(ControlMap::IntakeToggle)) {
			ControlMap::IntakeToggle = true;
		} else {
			ControlMap::IntakeToggle = false;
		}
	}

	if (!(ControlMap::IntakeToggle)) {
		if (_contGroup.Get(ControlMap::Outake)) {
			_intake.setIntake(IntakeStates::STOWED, IntakePower);
		} else {
			_intake.setIntake(IntakeStates::STOWED, -IntakePower);
		}
	} else {
		if (_contGroup.Get(ControlMap::Outake)) {
			_intake.setIntake(IntakeStates::DEPLOYED, IntakePower);
		} else {
			_intake.setIntake(IntakeStates::DEPLOYED, -IntakePower);
		}
	}
}