/*	Author: hbach003
 *  Partner(s) Name: Hannah Bach
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #5
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
        DDRD = 0x00; PORTD = 0xFF;
        DDRB = 0xFE; PORTB = 0x00;

    unsigned char tmpB = 0x00;
    unsigned short tmpD; // = 0;
    unsigned short sum = 0; 
    unsigned short tmpB0;

    while (1) {
       // tmpD = PIND << 1;
	tmpD = PIND;
	sum = tmpD << 1;

	tmpB0 = PINB & 0x01;
	sum = sum | tmpB0;

        if(sum >= 0x46) { //70 is 0x46 in hex
                tmpB = 0x02;
        }
        else if(sum > 0x05) {
                tmpB = 0x04;
        }
        else {
                tmpB = 0x00;
        }

        PORTB = tmpB;
   }
    return 0;
}



