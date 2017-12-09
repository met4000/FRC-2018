#include "WPILib.h"
#include "MyHeader.h"

using namespace frc;

// From MyHeader.h
int add(int a, int b) {
    return a + b;
}

class Robot: public IterativeRobot {
  XboxController *xbox = new XboxController(0);
  Talon *right_one, *right_two, *right_three, *left_one, *left_two, *left_three;
  TalonSRX *test;
public:
  double LY, RY;
    Robot() { }

    void RobotInit() {
      right_one = new Talon(0), right_two = new Talon(1), right_three = new Talon(2),
      left_one = new Talon(3), left_two = new Talon(4), left_three = new Talon(5);
    }
    void TankDrive(double l, double r) {
      right_one->Set(r);
      right_two->Set(r);
      right_three->Set(r);
      left_one->Set(l);
      left_two->Set(l);
      left_three->Set(l);
    }
    void DisabledInit() {
      TankDrive(0.0,0.0);
    }
    void AutonomousInit() { }
    void TeleopInit() { }
    void TestInit() { }

    void DisabledPeriodic() { }
    void AutonomousPeriodic() { }
    void TeleopPeriodic() {
      LY = xbox->GetRawAxis(1);
      RY = xbox->GetRawAxis(5);
      TankDrive(LY,RY);
    }
    void TestPeriodic() { }
};

START_ROBOT_CLASS(Robot)
