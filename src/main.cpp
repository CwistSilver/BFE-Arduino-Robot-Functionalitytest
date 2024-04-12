#include "BFEArduinoRobotFramework.h"
#include <Arduino.h>

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
  motorController.setDirection(motorController.FORWARD);
}

void loop()
{
  if (finished)
    return;
  if (sensorController.getDistance() > 10)
    motorController.drive();
  else
  {
    motorController.setDirection(motorController.NONE);
    lookLeftRight();
    motorController.rightTurn(180);
    finished = true;
  }
}
