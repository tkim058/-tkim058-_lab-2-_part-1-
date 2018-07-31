/*
 * moh008_lab2_part1.c
 *
 * Created: 2018-01-11 오후 4:31:02
 * Author : Lincoln
 */ 

#include <avr/io.h>

//bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b)
{
	return (b? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k)
{
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char counter = 0x00;
	unsigned char buttonA = 0x00;
	unsigned char buttonB = 0x00;
	
    while (1) 
    {
		counter = 0x00;
		buttonA = PINA & 0xFF;
		buttonB = PINB & 0xFF;
		
		for(int i = 0; i < 8; i++)
		{
			if(GetBit(buttonA, i))
			{
				counter++;
			}
		}
		for(int j = 0; j < 8; j++)
		{
			if(GetBit(buttonB, j))
			{
				counter++;
			}
		}
		PORTC = counter;
	}
}