/*	Author: Zion Gutierrez, zguti001
 *  Partner(s) Name: none
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Garage Door/ Light
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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA1 = 0x00; // Temporary variable to hold the value of PA1
	unsigned char tmpA0 = 0x00; // Temp variable to hold value of PA0
    
	while (1) {
	// 1) Read input
	tmpA0 = PINA & 0x01; // checking bit 0;
	tmpA1 = (PINA >> 1) & 0x01; //checking bit 1;
	
		// if PA0 is 1 AND PA1 = 0, set PB0 = 01, else = 00
		if (tmpA0 == 0x01 && tmpA1 == 0x00) { // True if PA0 is 1
			tmpB = (tmpB & 0xFE) | 0x01; // Sets tmpB to bbbbbb01
							 // (clear rightmost 2 bits, then set to 01)
		} else {
			tmpB = (tmpB & 0xFE) | 0x00; // Sets tmpB to bbbbbb10
							 // (clear rightmost 2 bits, then set to 00)
		}	
	// 3) Write output
        PORTB = tmpB;	
    }
    return 1;
}
