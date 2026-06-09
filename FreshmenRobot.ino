#include "driveSystem.h"

DriveSystem ds;
int testCount = 0;

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  Serial.println("Waiting 5 Seconds.......");
	delay(5000);

  ds.begin(1, 4);
  ds.setSpeed(100);
}

void loop(){
	Serial.print(testCount++);
	Serial.println(" Seconds Past");
	delay(1000);

	if (testCount % 2 == 0){
    ds.forward();
	}else{
    ds.release();
	}
}
