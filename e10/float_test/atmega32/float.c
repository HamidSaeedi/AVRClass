/*
 * float.c
 *
 * Created: 7/10/2025 4:23:56 PM
 * Author: Asus
 */

#include <io.h>
#include <stdio.h>
#include <stdint.h>
#include <delay.h>
#include <alcd.h>

uint8_t lcd_buffer[32];
float temp=45.76;

void main(void)
{
lcd_init(16);
while (1)
    {
    // Please write your application code here
     sprintf(lcd_buffer,"%02.2f",temp);
     lcd_puts(lcd_buffer);
     delay_ms(1000);
     lcd_clear();
    }
}
