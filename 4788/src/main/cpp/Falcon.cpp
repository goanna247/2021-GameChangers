#include "Falcon.h"
#include <iostream>

using namespace wml;
using namespace wml::controllers;

Falcon::Falcon(wml::TalonFX _falconMotor, 
               SmartControllerGroup &contGroup) : 
               _falconMotor(FalconMotor, 
               _contGroup(contGroup)) {}

void Falcon::TeleopOnUpdate(double dt) {
  if (_contGroup.Get(ControlMap::FalconRun)) {
    FalconPower = 0.2;
  } else {
    FalconPower = 0;
  }
  _falconMotor.transmission->SetVoltage(12 * FalconPower);
  std::cout << _falconMotor.GetEncoderTicks() << std::endl;

}

void Falcon::AutoOnUpdate(double dt) {}

void Falcon::TestOnUpdate(double dt) {}