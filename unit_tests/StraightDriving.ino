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
  static int prevLTicks = 0;
  static int prevRTicks = 0;

  int lTicks = ds.getLEncoder()->getTicks();
  int rTicks = ds.getREncoder()->getTicks();

  int dL = lTicks - prevLTicks;
  int dR = rTicks - prevRTicks;

  int absoluteError = lTicks - rTicks;
  int deltaError = dL - dR;

  float correctionDamping = 0.4;
  float correction = (
    (float)deltaError * correctionDamping +
    (float)absoluteError * correctionDamping
  );

  int spd = ds.getBaseSpeed();
  ds.setSpeed(
    spd + correction,
    spd - correction 
  );
}

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  startTime = millis();

  Serial.println("Waiting 5 Seconds...");
  delay(5000);

  ds.begin(
    L_MOTOR, R_MOTOR,
    L_ENCODER_A, L_ENCODER_B,
    R_ENCODER_A, R_ENCODER_B
  );
  Serial.println("Begin");

  ds.setBaseSpeed(100);
  ds.forward();
}

void loop(){
  // stop after 5 seconds
  if (millis() - startTime > 5000) return;

  correct();

}