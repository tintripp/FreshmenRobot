#pragma once

#include <Adafruit_MotorShield.h>
#include "motor.h"
#include "encoder.h"

class DriveSystem{
  private:
    Adafruit_MotorShield AFMS;

    Motor lm;
    Motor rm;
    Encoder le;
    Encoder re;
    
  public:
    DriveSystem();

    void begin(
      int lmotor, int rmotor, 
      int lenc_a, int lenc_b, 
      int renc_a, int renc_b
    );
    static DriveSystem* instance;

    /* Encoder Related Functions */

    void resetTicks();

    static void lInterrupt();
    static void rInterrupt();
    Encoder *getLEncoder();
    Encoder *getREncoder();

    /* Motor Related Functions */

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