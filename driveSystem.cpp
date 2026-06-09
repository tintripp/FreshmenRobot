#include "driveSystem.h"

DriveSystem::DriveSystem() {}

void DriveSystem::begin(int lport, int rport){
  AFMS = Adafruit_MotorShield();

  AFMS.begin();
  lm.begin(AFMS, lport);
  rm.begin(AFMS, rport);
  //Serial.println("DriveSystem: Motors Begin");
}

Motor *DriveSystem::getLMotor(){
  return &lm;
}
Motor *DriveSystem::getRMotor(){
  return &rm;
}

void DriveSystem::setSpeed(int ls, int rs){
  lm.setSpeed(ls);
  rm.setSpeed(rs);
}
void DriveSystem::setSpeed(int s){
  setSpeed(s, s);
}

void DriveSystem::backward(){
  lm.backward();
  rm.backward();
}
void DriveSystem::turnL(){
  lm.backward();
  rm.forward();
}
void DriveSystem::turnR(){
  lm.forward();
  rm.backward();
}
void DriveSystem::forward(){
  lm.forward();
  rm.forward();
}
void DriveSystem::release(){
  lm.release();
  rm.release();
}
