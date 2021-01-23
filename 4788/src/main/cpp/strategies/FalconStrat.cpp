#include "strategies/FalconStrat.h"

FalconStrategy::FalconStrategy(std::string name, Falcon &falcon, Controllers &contGroup) : Strategy(name), _falcon(falcon), _contGroup(contGroup) {}

void FalconStrategy::OnUpdate(double dt) {
  double powerOut = _contGroup.Get(ControlMap::FalconOn) > ControlMap::XboxDeadzone ? _contGroup.Get(ControlMap::FalconOn) : 0;
  if (powerOut != 0) {
  _falcon.setPower(0.2);
  } else {
    _falcon.setPower(0);
  }


  if (_contGroup.Get(ControlMap::EncoderRead, wml::controllers::Controller::ONFALL)) {
    _falcon.encoder();
  } else {}
}