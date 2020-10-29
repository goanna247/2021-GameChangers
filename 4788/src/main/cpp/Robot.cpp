#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

MotorControl mc;

// Robot Logiccd
void Robot::RobotInit() {}

void Robot::RobotPeriodic() {}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {

}
void Robot::TeleopPeriodic() {
	mc.update();
}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}