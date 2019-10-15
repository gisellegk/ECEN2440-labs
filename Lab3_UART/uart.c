/*
 * uart.c
 *
 *  Created on: Oct 14, 2019
 *      Author: Giselle
 */

#include 'msp.h'
#include 'uart.h'

#define fBRCLK 12000000 // Hz - input clock freq.


void config_uart(uint8_t baud){
    // set UCSWRST

    // initialize all eUSCI_A registers
    //// select SMCLK = 12MHz for this project
    UCA0CTLW0 |= 0b11 << UCSSEL_OFS; // apparently setting it to either 10b or 11b = SMCLK ?????
    //// BRDIV value (78) http://processors.wiki.ti.com/index.php/USCI_UART_Baud_Rate_Gen_Mode_Selection
    UCA0BRW = fBRCLK / baud;
    //// UCxBRF = 2
    UCA0BRF = 2;
    //// UCxBRS = 0
    UCA0BRS = 0;

    //// No parity
    //// LSB first
    //// one stop bit
    //// uart mode
    //// oversampling
    // configure ports
    // clear UCSWRST with software

}

void enable_uart(){
    // clear UCSWRST
    //
}

void disable_uart(){

}

void enable_interrupts(){
    // enable interrupts (optional) with UCRXIE or UCTXIE
}
