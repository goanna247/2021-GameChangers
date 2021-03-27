#include "strategies/DriveAuto.h"

DrivetrainAuto::DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp) : Strategy(name), _drivetrain(drivetrain), _wayFinder(wayFinder), _wp(wp) {
	Requires(&drivetrain);
	SetCanBeReused(true);
	SetCanBeInterrupted(true);

	// _wp.path = wayFinder.buildPath(_wp.spline1);

}

void DrivetrainAuto::OnUpdate(double dt) {
	if (_wayFinder.followPath(&_wp.pathL, dt, false)) {
		std::cout << "Path 1 complete" << std::endl;
		// if (_wayFinder.followPath(&_wp.pathL2, dt, false)) {
		// 	std::cout << "Path 2 complete" << std::endl;
		// }
	} else {
		std::cout << "ahhhhh" << std::endl;
	}
}