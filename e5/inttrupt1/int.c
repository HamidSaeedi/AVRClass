/*
 * int.c
 *
 * Created: 5/22/2025 7:04:00 PM
 * Author: Asus
 */

#include <io.h>
#include <alcd.h>
#include <stdio.h>
#include <stdint.h>
#include <delay.h>
#define LED_ON (PORTD= PIND | 0x01)
#define LED_OFF (PORTD= PIND & (~(0x01)))
#define BUTTON_PUSHED ((PINB >> 2) & 0x01)

char lcd_buffer[32];
uint8_t counter=0;

interrupt [19] void EXI2 (void)
{
    GIFR = GIFR & (~ (0x20)); 
    counter++;

} 

void main(void)
{
DDRD=255;
DDRB=0;
PORTB=255;
GICR = GICR | (1<<5);
//PORTD=0x01;
lcd_init(16);
# asm ("SEI")
while (1)
    { 
    /*  
    if(BUTTON_PUSHED == 0 )
    {
        counter++;
        if(counter>200)
            counter=0;
        while( BUTTON_PUSHED==0){}
    } 
    */
    // Please write your application code here
    //if(PIND==0x00)
    //counter++;
    //if(counter>200)
      // counter=0; 
    sprintf(lcd_buffer,"counter=%03d",counter);
    lcd_puts(lcd_buffer);  
    LED_ON;
    delay_ms(200);
    LED_OFF; 
    delay_ms(200);
    lcd_clear();
    }
}
