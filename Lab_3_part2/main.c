#include <msp.h>
#include "timerA0int.h"

void initButton();

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	config_interrupt_timer();
	config_interrupt_gpio();
	start_interrupt();
	while(1){

	    /*if((P1IN & 0b10) != 0b10){
	        //left button press
	        start_interrupt();
	    } else if((P1IN & 0b10000) != 0b10000){
	        //right button press
	        stop_interrupt();
	    }*/
	}

}


void initButton(){
    // set P1.1 and P1.4 as input
    P1DIR &= ~0b10010;
    // pull up resistor
    P1REN |= 0b10010; // enable pulling resistor
    P1OUT |= 0b10010; // this makes it pull up
}

void TA0_0_IRQHandler (void){
    //code goes here
    P2OUT ^= 0b100;
}
