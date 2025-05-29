/*
 * GccApplication1.c
 *
 * Created: 5/8/2025 4:36:05 PM
 * Author : Asus
 */ 
#define F_CPU 10000000
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>



int main(void)
{
	DDRC=0X0D;
	PORTC=0x00;
    /* Replace with your application code */
    while (1) 
    {
		if(PINC==)
		_delay_ms(100);
    }
}

