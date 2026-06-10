#pragma once

#include <Adafruit_MotorShield.h>

class Motor{
    private:
        Adafruit_DCMotor *motor;

        // keep speed in mem so we can return it
        int speed;
    
    public:
        Motor();
        void begin(Adafruit_MotorShield &AFMS, int port);
        
        void setSpeed(int s);
        int getSpeed();
        
        void backward();
        void forward();
        void release();
};