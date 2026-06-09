#include <Arduino.h>
#include "encoder.h"

#define TICKSPERMM 2.38732415

Encoder::Encoder() {}

void Encoder::begin(int a, int b, void (*interrupt)()){
  ticks = 0;

  pin_a = a;
  pin_b = b;

  //force pins to be high
  pinMode(pin_a, INPUT_PULLUP);
  pinMode(pin_b, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(pin_a),
    interrupt,
    CHANGE
  );
}
void Encoder::setReversed(bool r){
  isReversed = r;
}

void Encoder::tick(){
  static uint8_t lastA = 1;

  uint8_t a = digitalRead(pin_a);
  uint8_t b = digitalRead(pin_b);

  if (a != lastA) {
    if (a == b) ticks++;
    else ticks--;
  }

  lastA = a;
}
int Encoder::getTicks(){
  noInterrupts();
  long safeTicks = ticks;
  interrupts();

  if (isReversed) 
    safeTicks *= -1;

  return safeTicks;
}

// just assuming millimeters.
int Encoder::getDistance(){
  return getTicks() / TICKSPERMM;
}