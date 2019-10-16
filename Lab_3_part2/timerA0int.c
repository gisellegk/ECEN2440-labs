#include <msp.h>
#include "timerA0int.h"


#define SYSTEM_CLOCK        3000000/4  // [Hz] system_msp432p401r.c
#define Interrupt_frequency     20   // [Hz] PWM frequency desired
#define CALC_PERIOD(X)      (SYSTEM_CLOCK / X) //Calculate # of ticks in period

void config_interrupt_timer(void){

    TA0CTL &= ~0x0030; //Sets the timer to stop mode (halts timer)
    TA0CTL |= 0b100; // Clears the previous values of the timer

    TA0CTL |= 0b1000000000; // Setting timer to SMCLK (set 1 in bit 9) and then set 0 in bit 8
    TA0CTL &= ~0b100000000;
    TA0CTL |= 0b0010000000; // Increase the number of ticks by dividing value by 4 (set bit 7 to 1)

    TA0CCTL0 &= ~0x101; //Set timer to compare mode (bit 8 to 1) and clears pending flag
    TA0CCTL0 |= 1 << CCIE_OFS; //Enables the interrupt in TA0
    TA0CTL |= 0b10; //Enables timer interrupt number 8

    NVIC_EnableIRQ(TA0_0_IRQn); //Enables global interrupts
    __NVIC_SetPriority(TA0_0_IRQn, 2); //Sets the priority of interrupt 8 to 2

    TA0CCR0 = CALC_PERIOD(Interrupt_frequency);//Set CCR0 to the # of ticks in period for 50ms
}


void start_interrupt(void){
    TA0CTL |= 0b010000; //Sets the timer to up mode (starts timer)
    TA0CTL &= ~0b100000;
}

void stop_interrupt(void){
    TA0CTL &= ~0x30;    //Sets the timer to stop mode (halts timer)
}


void config_interrupt_gpio(void){
    P2OUT &= ~0b100; //Clears the previous values of port 2 pin 4

    P2DIR |= 0b100; //Sets pin 4 to output


}

void TA0_0_IRQHandler (void){
    if(TA0CCTL0 & 0b1){
        P2OUT ^= 0b100;
        TA0CCTL0 &= ~0b1; //clear flag pending? i hope?
    }
}

