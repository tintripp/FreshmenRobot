#include "encoder.h"

// ENCODER L: 5, 6      B, A
// ENCODER R: 9, 10     B, A

Encoder lEncoder;
Encoder rEncoder;

// these must be global
void lInterrupt() { lEncoder.tick(); }
void rInterrupt() { rEncoder.tick(); }

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  Serial.println("Begin");

  lEncoder.begin(6,  5, lInterrupt);
  rEncoder.begin(10, 9, rInterrupt);
  rEncoder.setReversed(true);
}

void loop(){
  Serial.print("lticks: ");
  Serial.print(lEncoder.getTicks());
  Serial.print("\trticks: ");
  Serial.print(rEncoder.getTicks());
  Serial.println();
	delay(16);
}