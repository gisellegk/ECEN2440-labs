/*
 *
 * Date         :
 * Author       :
*/

//**********INCLUDES*****************
#include "msp.h"

//*************DEFINITIONS***********
#define LED_ON_DELAY   100000
#define LED_OFF_DELAY  50000

//**********************************

/**
 * main.c
 */
void main(void)
{
    //Variables
    int i;           //For Loop

    //Setup

    P2DIR |= 0x7;     // Set as output
    P2OUT |= 0x7;     // Set to 0state


    while(1){
        //LED ON
        P2OUT |= 0x7;
        for( i =0; i < LED_ON_DELAY; i++);

        //LED OFF
        P2OUT &= ~0x07;

        for( i=0; i < LED_OFF_DELAY; i++);

    }
    return 0;
}
