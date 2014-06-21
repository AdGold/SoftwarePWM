/*
 * PWM library for non-PWM pins, ed1
 */

#include "PWM.h"

PWM::PWM()
{
  for (int i = 0; i < 8; i++)leds[i] = 0;
  for (int i = 0; i < 20; i++)pins[i] = -1;
  //last = 0;
  lastLedsOn = 0;
  timer = 0;
}

void PWM::analogWrite(int pin, int duty)
{
  //pins 0-19 are normal, 20-27 are LED shift register
  if (pin < 20) pins[pin] = duty;
  else if (pin < 28) leds[pin-20] = duty;
}

void PWM::update()
{
  //while (millis() - last < UPDATE_CYCLE);
  if (++timer == 256)timer = 0;
  int ledsOn = 0;
  for (int i = 0; i < 8; i++)
  {
    if (timer < leds[i]) ledsOn |= (1<<i);
  }
  if (ledsOn != lastLedsOn)
  {
    led(ledsOn);
    lastLedsOn = ledsOn;
  }
  for (int i = 0; i < 20; i++)
  {
    if (pins[i] == 0)
    {
      digitalWrite(i, LOW);
      pins[i] = -1;
    }
    else if (pins[i] > 0)
    {
      digitalWrite(i, (timer < pins[i])?HIGH:LOW);
    }
  }
  //last = millis();
}

void PWM::begin()
{
  pinMode(LATCH, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void PWM::delay(int n)
{
  unsigned long time = millis();
  while (millis() - time < n)update();
}

void PWM::led(int n)
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, n);
  digitalWrite(LATCH, HIGH);
}
