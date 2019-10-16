#include "msp.h"
#include "drv2605l.h"
//#include "pwm.h"
#include "i2c.h"
#include "gpio.h"

/**
 * main.c
 */
int butt(int int_butt){
   return int_butt = 0; //remove butt for final submission :)
}

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	int (*butt_ptr)(int) = &butt;
	config_drv2605l(butt_ptr); //what
}



