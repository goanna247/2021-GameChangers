#pragma once 

#include "controllers/Controllers.h"
#include "RobotMap.h"

class Falcon {
  public:
    Falcon(wml::TalonFX _falconMotor,
           wml::controllers::SmartControllerGroup &contGroup);

    void TeleopOnUpdate(double dt);
    void AutoOnUpdate(double dt);
    void TestOnUpdate(double dt);

  private: 
    wml::controllers::SmartControllerGroup &_contGroup

    frc::Timer timer;
    double FalconPower = 0;
}