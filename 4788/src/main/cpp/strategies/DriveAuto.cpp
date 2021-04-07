#include "strategies/DriveAuto.h"

DrivetrainAuto::DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp) : Strategy(name), _drivetrain(drivetrain), _wayFinder(wayFinder), _wp(wp) {
	Requires(&drivetrain);
	SetCanBeReused(true);
	SetCanBeInterrupted(true);

	pathIncrementer = 0;
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

			case 1:
				_wayFinder.resetGyro();
				pathIncrementer = 2;
				break;
			break;

			case 2:
				if (_wayFinder.followPath(&_wp.path2L, dt, true)) {
					pathIncrementer = 3;
				}
			break;

			case 3:
				if (_wayFinder.followPath(&_wp.path3L, dt, true)) {
					pathIncrementer = 4;
				}
			break;
			case 4:
				if (_wayFinder.followPath(&_wp.path4L, dt, true)) {
					pathIncrementer = 4;
				}
			break;
			case 5:
				_drivetrain.Set(0, 0);
			default:
				std::cout << "default running" << std::endl;
		}

	} catch (...) {
		std::cout << "error" << std::endl;
	}

	
}