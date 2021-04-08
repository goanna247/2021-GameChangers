#include "Intake.h"
#include "strategy/strategySystem.h"

using Controllers = wml::controllers::SmartControllerGroup;

class IntakeAutoStrategy : public wml::Strategy {
	public:
		IntakeAutoStrategy(std::string name, Intake &intake, Controllers &contGroup);

		void OnUpdate(double dt) override;
	private:
		Intake &_intake;
		Controllers &_contGroup;
};