/*
 * T.c
 *
 * Created: 5/29/2025 7:30:19 PM
 * Author: Asus
 */

#include <io.h>
#include <stdint.h>
#include <stdio.h>
#include <delay.h>
#include <alcd.h>

char lcd_buffer[32];
uint8_t count=0;
void main(void)
{
TCCR0 = TCCR0 | 0x05;

lcd_init(16);
while (1)
    {
    // Please write your application code here
    lcd_gotoxy(0,0);  
    sprintf(lcd_buffer,"TCNT0=%d",count);
    lcd_puts(lcd_buffer);
    count=TCNT0;
    delay_ms(1);

    }
}
