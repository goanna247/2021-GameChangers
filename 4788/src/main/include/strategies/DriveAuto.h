#pragma once 

#include "RobotMap.h"
#include "strategy/Strategy.h"
#include "strategies/DriveSystem.h"
#include "wfd_paths.h"

class DrivetrainAuto : public wml::Strategy {
 public:
	DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp);

	void OnUpdate(double dt) override;

 private:
	wml::Drivetrain &_drivetrain;
	wayfinder::WayFinder &_wayFinder;
	wfd_paths &_wp;
	bool _path1Complete = false;
	bool pathOneCompleted = false;
	int pathIncrementer = 0;
};