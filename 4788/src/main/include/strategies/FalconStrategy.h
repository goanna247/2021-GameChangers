#include "Falcon.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class FalconStrategy : public wml::Strategy {
  public:
    FalconStrategy(std::string name, Falcon &falcon, Controllers &contGroup);

    void OnUpdate(double dt) override;

  private:
    Falcon &_falcon;
    Controllers &_contGroup;
};