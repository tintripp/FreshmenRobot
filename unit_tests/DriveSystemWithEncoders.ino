#include "driveSystem.h"

#define LMOTOR 1
#define RMOTOR 4
#define LENC_A 6
#define LENC_B 5
#define RENC_A 10
#define RENC_B 9

DriveSystem ds;

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  ds.begin(
    LMOTOR, RMOTOR,
    LENC_A, LENC_B,
    RENC_A, RENC_B
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