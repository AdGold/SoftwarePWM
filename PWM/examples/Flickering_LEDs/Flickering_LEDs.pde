#include <PWM.h>

PWM pwm;

void setup()
{
  pwm.begin();
  randomSeed(analogRead(1));
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    pwm.analogWrite(20+i, random(120)+135);
  }
  pwm.delay(random(100));
}
