#include "strategies/DriveAuto.h"

DrivetrainAuto::DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp) : Strategy(name), _drivetrain(drivetrain), _wayFinder(wayFinder), _wp(wp) {
	Requires(&drivetrain);
	SetCanBeReused(true);
	SetCanBeInterrupted(true);

	// _wp.path = wayFinder.buildPath(_wp.spline1);

}

void DrivetrainAuto::OnUpdate(double dt) {

	std::cout << pathIncrementer << std::endl;
	try {
		switch (pathIncrementer) {
			case 0:
					if (_wayFinder.followPath(&_wp.path1L, dt, false)) {
						pathIncrementer = 1;
					}
				break;
			default:
				std::cout << "default running" << std::endl;
		}

	} catch (...) {
		std::cout << "error" << std::endl;
	}

	
}