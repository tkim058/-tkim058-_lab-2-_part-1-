/*
 * [tkim058]_lab[2]_part[1].c
 * Partner(s) Name & E-mail: Lincoln Oh
 * Lab Section: B01
 * Assignment: Lab #1  Exercise #2
 * Exercise Description: [Count number of 1 in A and B and return on C]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
   DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
   DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs,
   DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
  
   unsigned char counter = 0;
   unsigned char tmpA = 0x00;
   unsigned char tmpB = 0x00;
   
    while (1) 
    {
		counter = 0;
		tmpA = PINA & 0xFF;
		tmpB = PINB & 0xFF;
		
		for(int i=0;i<8;++i)
		{
			if (GetBit(tmpA, i))
			{
				counter++;
			}
		}
		for(int i=0;i<8;++i)
		{
			if (GetBit(tmpB, i))
			{
				counter++;
			}
		}
		PORTC = counter;
	}
}

