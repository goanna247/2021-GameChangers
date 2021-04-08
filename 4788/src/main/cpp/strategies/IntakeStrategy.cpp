#include "strategies/IntakeStrategy.h" 

IntakeAutoStrategy::IntakeAutoStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
	Requires(&intake);
	SetCanBeReused(true);
	SetCanBeInterrupted(true);
}

void IntakeAutoStrategy::OnUpdate(double dt) {
	_intake.setIntake(0.8);
	_intake.setMag(0.15);

}