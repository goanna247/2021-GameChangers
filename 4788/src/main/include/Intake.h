#pragma once 

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

class Intake : public wml::StrategySystem {
	public:
		Intake(wml::TalonSrx &intakeMotor, wml::TalonSrx &magMotor);

		void setIntake(double power = 0);
		void setMag(double power = 0);

		void updateIntake(double dt);
		void update(double dt);
	private:
		wml::TalonSrx &_intakeMotor;
		wml::TalonSrx &_magMotor;

		double _IntakePower;
		double _MagPower;
};