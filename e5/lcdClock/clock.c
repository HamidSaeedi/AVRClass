/*
 * clock.c
 *
 * Created: 5/22/2025 4:27:43 PM
 * Author: Asus
 */

#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>
#include <stdint.h>
uint8_t s=45;
uint8_t m=32;
uint8_t h=8;
char lcd_buffer[32];
void main(void)
{
lcd_init(16);
while (1)
    {
    // Please write your application code here
    lcd_clear();
    s++;
    if(s>59)
    {
        s=0;
        m++;
        if(m>59)
        {
            m=0;
            h++;
            if(h>23)
            {
                h=0;
            }
        }
    }
    sprintf(lcd_buffer,"%02d:%02d:%02d",h,m,s);
    lcd_puts(lcd_buffer);
    delay_ms(1000);
    }
}
