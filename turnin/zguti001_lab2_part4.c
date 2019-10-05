/*	Author: Zion Gutierrez, zguti001
 *      Partner(s) Name: none
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: Parking Spot Available Counter + Flag for Lot Full
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#define totalWeightKg (TempA + TempB + TempC)
#define DifferenceAC (TempA - TempC)

int main(void) {
        DDRA = 0x00; PORTA = 0xFF; // Config port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Config port B's 8 pins to inputs
        DDRC = 0x00; PORTC = 0xFF; // Config port C's 8 pins to inputs
	DDRD = 0xFF; PORTD = 0x00; // Config port D's 8 pins as outputs, initialize to 0s
	unsigned char TempA = 0x00; // Temp (PORTA, weight 0-255kg)
    	unsigned char TempB = 0x00; // Temp (PORTB, weight)
        unsigned char TempC = 0x00; // Temp (PORTC, weight)
	unsigned char TempD = 0x00; // Temp (PDO, < 140kg / PD1, (A minus C) > 80kg / PD2:7, tot weight)
	unsigned char weightTemp = totalWeightKg;

	while (1) {
	// Input
	TempA = PORTA;
	TempB = PORTB;
	TempC = PORTC;

	if( totalWeightKg > 0x8C ){         //If totalWeight too large, set PD0 to 1 
		TempD = TempD | 0x01; }
	
	if( DifferenceAC > 0x50 ){          //If difference too large, set P1 to 1
		TempD = TempD | 0x02; }
	
	// 3) Write output
        weightTemp = weightTemp & 0xFC;   //clear last two bits, approximate
	TempD = TempD | weightTemp;       //add those to TempD and keep old bits
        
	PORTD = TempD;	
    }

    return 1;
}
