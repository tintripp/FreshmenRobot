#pragma once

class Encoder{
  private:
    bool isReversed;
    volatile long ticks;
    int pin_a;
    int pin_b;
  
  public:
    Encoder();

    void begin(int a, int b, void (*interrupt)());
    void setReversed(bool r);
    void tick();

    int getTicks();
    int getDistance();
    
};