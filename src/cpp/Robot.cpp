#include "WPILib.h"
#include "MyHeader.h"

using namespace frc;

// From MyHeader.h
int add(int a, int b) {
    return a + b;
}

class Robot: public IterativeRobot {
  XboxController *xbox = new XboxController(0);
  TalonSRX *right_one = new TalonSRX(0), *right_two = new TalonSRX(1), *right_three = new TalonSRX(2), *left_one = new TalonSRX(3), *left_two = new TalonSRX(4), *left_three = new TalonSRX(5)
  RobotDrive *robot = new RobotDrive();
public:
  double LY, RY;
    Robot() { }

    void RobotInit() {
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
