#include "Falcon.h"

Falcon::Falcon(wml::TalonFX &falconMotor) : _falconMotor(falconMotor) {}

void Falcon::setPower(double power) {
  _power = power;
}

void Falcon::encoder() {
  std::cout << _falconMotor.GetEncoderTicks() << std::endl;
}

void Falcon::updateFalcon(double dt) {
  
}

void Falcon::update(double dt) {
  updateFalcon(dt);
}

