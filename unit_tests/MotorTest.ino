#include "motor.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Motor lMotor;
Motor rMotor;
int testCount = 0;

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  Serial.println("Waiting 5 Seconds.......");
	delay(5000);

  AFMS.begin();
  lMotor.begin(AFMS, 1);
  rMotor.begin(AFMS, 4);
  Serial.println("Motors Begin");

  lMotor.setSpeed(100);
  rMotor.setSpeed(100);
  Serial.println("Set Motor Speeds");
}

void loop(){
	Serial.print(testCount++);
	Serial.println(" Seconds Past");
	delay(1000);

	if (testCount % 2 == 0){
    lMotor.forward();
    rMotor.forward();
	}else{
    lMotor.release();
    rMotor.release();
	}
}

