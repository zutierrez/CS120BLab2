/*	Author: zguti001
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
        DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char inputA = 0x00; // Temp (PORTA, bits represent spaces)
    	unsigned char cntavail = 0x04; //Temp (PORTC, amount of empty spaces)

	while (1) {
	// Input
	inputA = PINA; //
	

	if( ((inputA & 0xFE) >> 0) == 1 ){
		cntavail -= 1;}
	if ( ((inputA & 0xFD) >> 1) == 1 ){
		cntavail -=1;}
	if( ((inputA & 0xFC) >> 2) == 1 ){
		cntavail -= 1;}
	if ( ((inputA & 0xFB) >> 3) == 1 ){
		cntavail -=1;}

	// 3) Write output
        PORTC = cntavail;	
    }
    return 1;
}
