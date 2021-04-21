#pragma once

#include "strategy/StrategySystem.h"
#include "RobotMap.h"

enum class ShooterState {
	ON,
	OFF,
};

class Shooter : public wml::StrategySystem {
 public:
	Shooter(wml::TalonFX &flyWheelMotor, wml::TalonSrx &hoodMotor, wml::TalonSrx &turretMotor, wml::TalonSrx &fireMotor);

	void setFlywheel(double power);
	void setHood(double power );
	void setTurret(double power );
	void setFire(double power);

	void updateShooter(double dt);
	void update(double dt);

 private:
	wml::TalonFX &_flyWheelMotor;
	wml::TalonSrx &_hoodMotor;
	wml::TalonSrx &_turretMotor;
	wml::TalonSrx &_fireMotor;

	ShooterState _shooterState{ShooterState::ON};

	double _flywheelPower;
	double _turretPower;
	double _hoodPower;
	double _firePower;
};