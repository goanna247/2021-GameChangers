#include "Intake.h"

Intake::Intake(wml::TalonSrx &intakeMotor, wml::TalonSrx &magMotor) : _intakeMotor(intakeMotor), _magMotor(magMotor) {}

void Intake::setIntake(double power) {
	_IntakePower = power;
}

void Intake::setMag(double power) {
	_MagPower = power;
}

void Intake::updateIntake(double dt) {
	_intakeMotor.Set(_IntakePower);
	_magMotor.Set(_MagPower);
	std::cout << "IntakePower: " << _IntakePower << std::endl;
	std::cout << "Mag Power: " << _MagPower << std::endl;
}

void Intake::update(double dt) {
	updateIntake(dt);
}