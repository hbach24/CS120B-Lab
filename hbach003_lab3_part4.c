/*	Author: hbach003
 *  Partner(s) Name: Hannah Bach
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #4
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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char upNibA;
	unsigned char lowNibA;
	unsigned char shiftUpNibA;
	unsigned char shiftLowNibA;
	unsigned char tmpC = 0x00;
	unsigned char tmpB = 0x00;

    /* Insert your solution below */
    while (1) {
	upNibA = PINA & 0xF0;
	shiftUpNibA = upNibA >> 4;
	lowNibA = PINA & 0x0F;
	shiftLowNibA = lowNibA << 4;
	
	//tmpC = PINC;
	//tmpB = PINB;
	//tmpC = tmpC & 0x0F; //clear C's upper nibble
	//tmpB = tmpB & 0xF0; //clear B's lower nibble

	PORTB = tmpB | shiftUpNibA;
	PORTC = tmpC | shiftLowNibA;
    }
    return 0;
}
