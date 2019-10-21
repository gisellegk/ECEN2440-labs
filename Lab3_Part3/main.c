#include "msp.h"
#include "drv2605l.h"
#include "pwm.h"
#include "i2c.h"
#include "gpio.h"

/**
 * main.c
 */

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	config_i2c();
	config_pwm_timer();
	config_pwm_gpio();
	start_pwm(50);
	config_drv2605l();
	while(1){
	}

}



