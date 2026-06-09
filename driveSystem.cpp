#include "driveSystem.h"

DriveSystem::DriveSystem() {}

DriveSystem* DriveSystem::instance = nullptr;

void DriveSystem::begin(
  int lmotor, int rmotor, 
  int lenc_a, int lenc_b, 
  int renc_a, int renc_b
){
  instance = this;
  AFMS = Adafruit_MotorShield();

  AFMS.begin();
  lm.begin(AFMS, lmotor);
  rm.begin(AFMS, rmotor);
  Serial.println("DriveSystem: Motors Begin");

  le.begin(lenc_a, lenc_b, lInterrupt);
  re.begin(renc_a, renc_b, rInterrupt);
  re.setReversed(true);
  Serial.println("DriveSystem: Encoders Begin");
}

/* Encoder Related Functions */

void DriveSystem::resetTicks(){
  le.resetTicks();
  re.resetTicks();
}

void DriveSystem::lInterrupt() { if (instance) instance->le.tick(); }
void DriveSystem::rInterrupt() { if (instance) instance->re.tick(); }

Encoder *DriveSystem::getLEncoder(){ return &le; }
Encoder *DriveSystem::getREncoder(){ return &re; }

/* Motor Related Functions */

Motor *DriveSystem::getLMotor(){ return &lm; }
Motor *DriveSystem::getRMotor(){ return &rm; }

void DriveSystem::setSpeed(int ls, int rs){
  lm.setSpeed(ls);
  rm.setSpeed(rs);
}
void DriveSystem::setBaseSpeed(int s){
  base_speed = s;
  setSpeed(s, s);
}
int DriveSystem::getBaseSpeed(){
  return base_speed;
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
