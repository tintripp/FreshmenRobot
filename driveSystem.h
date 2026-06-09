#pragma once

#include <Adafruit_MotorShield.h>
#include "motor.h"

class DriveSystem{
  private:
    Adafruit_MotorShield AFMS;

    Motor lm;
    Motor rm;
    
  public:
    DriveSystem();
    void begin(int lport, int rport);

    Motor *getLMotor();
    Motor *getRMotor();

    void setSpeed(int ls, int rs);
    void setSpeed(int s);

    // these methods make the motors actually move
    void backward();
    void turnL();
    void turnR();
    void forward();
    void release();
};