
/* ECEN 2440
 * Lab 3, Part 2 - Interrupt with Timer A0
 * Phaedra Curlin, Nanu Dahal, Giselle Koo
 */

#include <msp.h>
#include "timerA0int.h"

/*
*
*/

void main(void)
{

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;      //Halts the watchdog timer of the MSP432
	config_interrupt_timer();                        //Configures the interrupt and timer in timerA0int.c
	config_interrupt_gpio();                         //Configures P2.2 to be used with the timer
	start_interrupt();                               //Initializes the interrupt
}


