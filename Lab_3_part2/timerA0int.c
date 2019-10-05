#include <msp.h>
#include "timerA0int.h"


#define SYSTEM_CLOCK        3000000/4  // [Hz] system_msp432p401r.c
#define Interrupt_frequency     20   // [Hz] PWM frequency desired
#define CALC_PERIOD(X)      (SYSTEM_CLOCK / X) //calc # of ticks in period


void config_interrupt_timer(void){
    TA0CTL &= ~0x0030; //halted timer (stop mode)
    TA0CTL |= 0b100; // CLR

    TA0CTL |= 0b1000000000; // SMCLK set 1 in bit 9
    TA0CTL &= ~0b100000000; // SMCLK set 0 in bit 8
    TA0CTL |= 0b0010000000; // div by 4 set bit 7 to 1
    //TA0CTL &= ~0b1000000; //div by 4 set bit 6 to 0
    TA0CCTL1 &= ~0x101; //set to compare mode in bit 8 & cleared flag pending
    TA0CCTL1 |= 0x0E0; //0b 1110 0000; //set mode 7 (reset set)
    TA0CTL |= 0b10; //enable timer interrupt 8


    NVIC_EnableIRQ(TA0_0_IRQn); //enabled everything
    __enable_irq(); //enable global interrupts
    __NVIC_SetPriority(TA0_0_IRQn, 2);
    //NVIC->IPR2 |= 0x20;//set priority of interrupt 8 to 2
    //priority

    TA0CCR0 = CALC_PERIOD(Interrupt_frequency);//# of ticks in period for 50ms
    //TA0CCR1 =  TA0CCR0 * 25 / 100;//we need to have CCR0 = to 50 ms cycles       //don't think we need it

}


void start_interrupt(void){
    TA0CTL |= 0b010000; //up mode
    TA0CTL &= ~0b100000;//up mode pt 2
}

void stop_interrupt(void){
    TA0CTL &= ~0x30;//0011 0000 (stop mode) halts timer

}


void config_interrupt_gpio(void){
    P2OUT &= ~0b100; // clear pin 4 (not sure if this is necessary)
    //we want bit #4 to be 0, 1 in SEL1 and SEL0 respectively for primary module function
    P2DIR |= 0b100; //set as output 1000


}



