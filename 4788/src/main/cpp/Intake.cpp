#include "Intake.h"

Intake::Intake(wml::TalonSrx &intakeMotor, wml::actuators::DoubleSolenoid &intakeSolenoid) : _intakeMotor(intakeMotor), _intakeSolenoid(intakeSolenoid) {}

/**
 * set state and power of the intake
 */
void Intake::setIntake(const IntakeStates st, double power) {
	_intakeState = st;
	_power = power;
}

void Intake::updateIntake(double dt) {
	double setPower = 0;

	switch (_intakeState) {
		case IntakeStates::STOWED:
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
			setPower = _power;
			break;
		case IntakeStates::DEPLOYED:
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
			setPower = _power;
			break;
	}

	_intakeMotor.Set(setPower);
	_intakeSolenoid.Update(dt);
}

void Intake::update(double dt) {
	updateIntake(dt);
}