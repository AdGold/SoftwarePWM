/*
 * PWM library for non-PWM pins, ed1
 */

#ifndef pwm_h
#define pwm_h

#include <Arduino.h>

#define UPDATE_CYCLE 1
#define CLOCK 10
#define LATCH 11
#define DATA 12

class PWM
{
  public:
    PWM();
    void analogWrite(int pin, int duty);
    void update();
    void begin();
    void delay(int n);
  private:
    unsigned long last;
    int timer;
    int pins[20];
    int lastLedsOn, leds[8];
    void led(int n);
};

#endif //pwm_h

