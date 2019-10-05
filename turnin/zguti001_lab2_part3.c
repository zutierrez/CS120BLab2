/*	Author: Zion Gutierrez, zguti001
 *      Partner(s) Name: none
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: Parking Spot Available Counter + Flag for Lot Full
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#define spot4 (PINA & 0x08) >> 3
#define spot3 (PINA & 0x04) >> 2
#define spot2 (PINA & 0x02) >> 1
#define spot1 (PINA & 0x01) >> 0

int main(void) {
        DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	//unsigned char inputA = 0x00; // Temp (PORTA, bits represent spaces)
    	unsigned char cntavail = 0x00; //Temp (PORTC, amount of empty spaces)
        unsigned char outputC = 0x00;

	while (1) {
	// Input

	if( spot4 == 0 ){
		cntavail = cntavail + 1; }
	
	if( spot3 == 0 ){
		cntavail = cntavail + 1;}
	
	if( spot2 == 0 ){
		cntavail = cntavail + 1;}
	
	if( spot1  == 0 ){
		cntavail = cntavail + 1;}

        if(cntavail == 0x00){
		cntavail = cntavail | 0x80;}

        // Output
        outputC = cntavail;
	PORTC = outputC;
	cntavail = 0x00;	
    }

    return 1;
}
