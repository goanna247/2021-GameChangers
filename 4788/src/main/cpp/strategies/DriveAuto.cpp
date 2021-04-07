#include "strategies/DriveAuto.h"

DrivetrainAuto::DrivetrainAuto(std::string name, wml::Drivetrain &drivetrain, wayfinder::WayFinder &wayFinder, wfd_paths &wp) : Strategy(name), _drivetrain(drivetrain), _wayFinder(wayFinder), _wp(wp) {
	Requires(&drivetrain);
	SetCanBeReused(true);
	SetCanBeInterrupted(true);

	// _wp.path = wayFinder.buildPath(_wp.spline1);

}

void DrivetrainAuto::OnUpdate(double dt) {

	// if (_path1Complete) {
	// 	if (_wayFinder.followPath(&_wp.path2L, dt, false)) {
	// 		std::cout << "Path 2 complete" << std::endl;
	// 	} else {
	// 		std::cout << "Following path 2" << std::endl;
	// 	}
	// }


	// if (!_path1Complete) {
	// 	if (_wayFinder.followPath(&_wp.path1L, dt, false)) {
	// 		std::cout << "Path 1 complete" << std::endl;
	// 		_drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	// 		_drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();
	// 		_path1Complete = true;


	// 		// if (_wayFinder.followPath(&_wp.pathL2, dt, false)) {
	// 		// 	std::cout << "Path 2 complete" << std::endl;
	// 		// }
	// 	} else {
	// 		// std::cout << "ahhhhh" << st d::endl;
	// 		std::cout << "Following path 1" << std::endl;
	// 	}
	// }

	// if ( _wayFinder.followPath(&_wp.path1L, dt, false)) {
	// 	// //reset gyro 
	// 	// if (!gyroReset) {
	// 	// 	// _drivetrain.gyro.Reset();
	// 	// 	// RobotMap.driveSystem.gyro.Reset();
	// 	// 	_wayFinder.resetGyro();
	// 	// 	gyroReset = true;
	// 	// } else {
	// 	// 	std::cout << "finished first path" << std::endl;
	// 	// 	if (_wayFinder.followPath(&_wp.path2L, dt, false)) {
	// 	// 		std::cout << "finished second path" << std::endl;
	// 	// 	}
			
	// 	// }
	// 	_wayFinder.followPath(&_wp.path2L, dt, false);
	// } else {
	// 	// _wayFinder.followPath(&_wp.path2L, dt, false);
	// }
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
			case 2:
				if (_wayFinder.followPath(&_wp.path2L, dt, false)) {
					pathIncrementer = 2;
				}
			break;
			default:
				std::cout << "default running" << std::endl;
		}

	} catch (...) {
		std::cout << "error" << std::endl;
	}

	
}