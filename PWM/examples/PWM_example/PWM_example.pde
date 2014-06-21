//Fades all 8 LEDs on and off

#include <PWM.h>

PWM pwm;

void setup()
{
  pwm.begin();
}

void loop()
{
  for (int x=0; x<180; x++) {
    // convert degrees to radians
    // then obtain sin value
    float sinVal = (sin(x*(3.1412/180)));
    int ledVal = int(sinVal*250) + 5; //keep between 5 & 255
    for (int i = 0; i < 8; i++) pwm.analogWrite(20+i, ledVal);
    pwm.delay(25);
  }
}
