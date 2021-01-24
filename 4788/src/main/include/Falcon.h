#pragma once 

#include "strategy/Strategy.h"
#include "RobotMap.h"

enum class FalconStates {
  ON,
  OFF,
};

class Falcon : public wml::StrategySystem {
  public:
    Falcon(wml::TalonFX &falconMotor);

    void setPower(double power = 0);
    void encoder();

    void updateFalcon(double dt);

    void update(double dt);

  private:
    wml::TalonFX &_falconMotor;

    FalconStates _falconState{ FalconStates::OFF };

    double _power;
};