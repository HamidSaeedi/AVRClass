/*
 * B.c
 *
 * Created: 7/24/2025 6:10:36 PM
 * Author: Asus
 */

#include <io.h>
#include <alcd.h>
#include <stdio.h>
#include <stdint.h>
#include <delay.h>

uint8_t BPUSH;
uint8_t LCD_ON=0;
uint8_t TIM0_Count=0;
    


interrupt [19] void BUTTON1 (void)
{
     BPUSH=1;
}

interrupt [10] void TIM1 (void)
{
  TCNT0=0xB2;
   TIM0_Count++;
  if(TIM0_Count>200)
  {
    TIM0_Count=0;
    if(LCD_ON==1)
    {
        LCD_ON=0;
        lcd_clear();
    }
  }
  
  if(BPUSH==1)
  {
        lcd_puts("HI!"); 
        BPUSH=0;
        LCD_ON=1;
        TIM0_Count=0;
        //lcd_clear();
  }
    
}


void main(void)
{
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 9.984 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
// Timer(s)/Counter(s) Interrupt(s) initialization
// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
TCNT0=0xB2;
OCR0=0x00;
GICR |= 1<<5;
lcd_init(16);
#asm("SEI")
while (1)
    {
    // Please write your application code here

}
}
