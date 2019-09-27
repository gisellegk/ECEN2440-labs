
#include "msp.h"
#include "pwm.h"


void initButton(){
    // set P1.1 and P1.4 as input
    P1DIR &= ~0b10010;
    // pull up resistor
    P1REN |= 0b10010; // enable pulling resistor
    P1OUT |= 0b10010; // this makes it pull up
}

void main(void)
{
      initButton();
      config_pwm_timer();
      start_pwm(25);
      config_pwm_gpio();
      int val = 50;
      while(1)
      {
          uint8_t var = P1IN & 0b10;
          if(var != 0b10)
          {
              //left button press
              stop_pwm();
          } else if( (P1IN & 0b10000) != 0b10000){
              //right button press
              start_pwm(val);
              val = (val + 25)%100;
          }
      }
      //stop_pwm();
}
