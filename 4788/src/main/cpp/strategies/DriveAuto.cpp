#include "strategies/DriveAuto.h"

DrivetrainAuto::DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp) : Strategy(name), _drivetrain(drivetrain), _wayFinder(wayFinder), _wp(wp) {
	Requires(&drivetrain);
	SetCanBeReused(true);
	SetCanBeInterrupted(true);

	// _wp.path = wayFinder.buildPath(_wp.spline1);
}

void DrivetrainAuto::OnUpdate(double dt) {

	if (_wayFinder.followPath(_wp.path, dt, false)) {
	  std::cout << "Path complete" << std::endl;
	} else { 
	  // std::cout << "Following path" << std::endl; 
		if (_wayFinder.atWayPoint(1, _wp.path)) {
			std::cout << "At way point 1" << std::endl;
		}
	}

	// _wayFinder.followPath(_wp.path, dt, false);

	// _wayFinder.testTurnPID(dt, *_wayFinder.getConfig(), 180); //turn 180 degrees using the PID config in robot.cpp
 //drive 2 meters forwards


	// if (nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("turnAround").GetDouble(0) == 0) {
	// 	_wayFinder.testTurnPID(dt, *_wayFinder.getConfig(), 180); //turn 180 degrees using the PID config in robot.cpp
	// } else if (nt::NetworkTableInstance::GetDefault().GetTable("WayFinder")->GetSubTable("Config")->GetEntry("turnAround").GetDouble(0) == 1) {
	// 	_wayFinder.testDrivePID(dt, *_wayFinder.getConfig(), 2);
	// } else {
	// 	_wayFinder.testPID(dt, *_wayFinder.getConfig(), 2, 10);
	// }
}