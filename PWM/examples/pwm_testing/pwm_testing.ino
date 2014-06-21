#include <PWM.h>

#define RED 15
#define GREEN 0
#define BLUE 14

PWM pwm;

void setup()
{
  pwm.begin();
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 256; i++)
  {
    pwm.analogWrite(RED, i);
    pwm.analogWrite(BLUE, i);
    pwm.analogWrite(GREEN, i);
    pwm.delay(50);
  }
}
