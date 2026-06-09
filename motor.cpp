#include "motor.h"

Motor::Motor(){}

void Motor::begin(Adafruit_MotorShield &AFMS, int port){
    motor = AFMS.getMotor(port);
    
    // This initializes the motor
    forward();
    release();
    setSpeed(0);

    Serial.print("Motor initiated on port ");
    Serial.println(port);
}

void Motor::setSpeed(int speed){
    motor->setSpeed(speed);
}
void Motor::backward(){
    motor->run(BACKWARD);
}
void Motor::forward(){
    motor->run(FORWARD);
}
void Motor::release(){
    motor->run(RELEASE);
}