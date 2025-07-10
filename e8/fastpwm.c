/*
 * fastpwm.c
 *
 * Created: 6/26/2025 4:27:21 PM
 * Author: Asus
 */

#include <io.h>
#include <stdint.h>
#include <stdio.h>
#include <delay.h>
void main(void)
{
TCCR0|=(1<<0)|(1<<2)|(1<<6)|(1<<3)|(1<<4)|(1<<5);
OCR0=0x33; //51  dutycycle = 100-20

while (1)
    {
    // Please write your application code here

    }
}
