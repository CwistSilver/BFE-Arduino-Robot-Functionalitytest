#include "BFEArduinoRobotFramework.h"

bool finished = false;

void lookLeftRight()
{
  servoController.setAngle(0);
  servoController.setAngle(180);
  servoController.setAngle(90);
}

void setup()
{
  arduinoSetup();
  motorController.driveForward();
}

void loop()
{
  if (finished)
    return;
  if (sensorController.getDistance() > 10)
    motorController.update();
  else
  {
    motorController.stop();
    lookLeftRight();
    motorController.rightTurn(180);
    finished = true;
  }
}
