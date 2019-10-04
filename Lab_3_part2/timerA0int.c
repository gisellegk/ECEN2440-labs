#include <msp.h>
#include "timerA0int.h"


#define SYSTEM_CLOCK        3000000  // [Hz] system_msp432p401r.c
#define PWM_FREQUENCY       100000   // [Hz] PWM frequency desired
#define CALC_PERIOD(X)      (SYSTEM_CLOCK / X) //calc # of ticks in period


void config_interrupt_timer(void){
    TA0CTL |= 0b100; // CLR
    TA0CTL |= 0b1000000000; // SMCLK set 1 in bit 9
    TA0CTL &= ~0b100000000; // SMCLK set 0 in bit 8
    TA0CCTL1 |= 0x0E0; //0b 1110 0000; //set mode 7 (reset set)
    TA0CTL |= 0b10; //enable timer interrupt
    NVIC_EnableIRQ(TA0_0_IRQn);
    //priority
}


void start_interrupt(uint8_t duty_cycle){
    TA0CTL |= 0b010000; //up mode
    TA0CTL &= ~0b100000;//up mode pt 2
}

void stop_interrupt(void){
    TA0CTL &= ~0x30;//0011 0000
}


void config_interrupt_gpio(void){

}



