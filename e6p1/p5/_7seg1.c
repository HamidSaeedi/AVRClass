/*
 * _7seg1.c
 *
 * Created: 6/15/2025 1:08:22 PM
 * Author: Asus
 */

#include <io.h>
#include <stdint.h>
#include <stdio.h>
#include <delay.h>
uint8_t _7segDataCC[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uint8_t i=0;
void main(void)
{
DDRB=0xff;
PORTB=0;
while (1)
    {
       for(i=0;i<10;i++)
       {
        PORTB=_7segDataCC[i];
        delay_ms(300);
       }

    }
}
