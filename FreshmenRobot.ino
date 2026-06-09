#include "driveSystem.h"

#define L_MOTOR 1
#define R_MOTOR 4
#define L_ENCODER_A 6
#define L_ENCODER_B 5
#define R_ENCODER_A 10
#define R_ENCODER_B 9

DriveSystem ds;

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  ds.begin(
    L_MOTOR, R_MOTOR,
    L_ENCODER_A, L_ENCODER_B,
    R_ENCODER_A, R_ENCODER_B
  );

  Serial.println("Begin");

}

void loop(){
  Serial.print("lticks: ");
  Serial.print(ds.getLEncoder()->getTicks());
  Serial.print("\trticks: ");
  Serial.print(ds.getREncoder()->getTicks());
  Serial.println();
	delay(16);
}