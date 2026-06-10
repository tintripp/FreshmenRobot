#include "driveSystem.h"

#define L_MOTOR 1
#define R_MOTOR 4
#define L_ENCODER_A 6
#define L_ENCODER_B 5
#define R_ENCODER_A 10
#define R_ENCODER_B 9

DriveSystem ds;
unsigned long startTime;

void correct(){
  static int oldL = 0;
  static int oldR = 0;
  int l = ds.getLEncoder()->getTicks();
  int r = ds.getREncoder()->getTicks();

  int deltaL = l - oldL;
  int deltaR = r - oldR;
  int error = deltaR - deltaL;

  float damping = 0.5;
  float correction = (float)error * damping;

  int base = ds.getBaseSpeed();
  ds.setSpeed(
    base + correction,
    base - correction 
  );

  oldL = l;
  oldR = r;
}

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  ds.begin(
    L_MOTOR, R_MOTOR,
    L_ENCODER_A, L_ENCODER_B,
    R_ENCODER_A, R_ENCODER_B
  );
  Serial.println("Begin");

  Serial.println("Waiting 5 Seconds...");
  delay(5000);
  Serial.println("Done Waiting");

  startTime = millis();

  ds.setBaseSpeed(100);
  ds.forward();
}

void loop(){
  // stop after 5 seconds
  if (millis() - startTime > 5000) {
    ds.release();
    return;
  }

  correct();

  // this didn't work when i updated less frequently
  // for some reason, 16 ms delay didn't work but 5 does.
  delay(5);

}