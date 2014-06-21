//Fades LED on pin 13 on and off
#include <PWM.h>
#define LED 13

PWM pwm;

void setup()
{
  pwm.begin();
  pinMode(LED, OUTPUT);
}

void loop()
{
  for (int x=0; x<180; x++) {
    int ledVal = int((sin(x*(3.1415/180)))*255);
    pwm.analogWrite(LED, ledVal);
    pwm.delay(25);
  }
}
