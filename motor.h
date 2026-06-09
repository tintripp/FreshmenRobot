#pragma once

#include <Adafruit_MotorShield.h>

class Motor{
    private:
        Adafruit_DCMotor *motor;
    
    public:
        Motor();
        void begin(Adafruit_MotorShield &AFMS, int port);
        
        void setSpeed(int speed);
        void backward();
        void forward();
        void release();
};