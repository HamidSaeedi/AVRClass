/*
 * clock.c
 *
 * Created: 7/24/2025 6:45:47 PM
 * Author: Asus
 */

#include <io.h>
#include <stdint.h>
#include <stdio.h>
#include <delay.h>

uint16_t shifter=1;
uint8_t data=2;
uint8_t h=12,m=17,s=56;
uint16_t TIM0_counter=0;
uint8_t blink=0;
uint8_t _7segDataCC[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void Extract(void);
interrupt [10] void TIM1 (void)
{
   TCNT0=0x83; 
   PORTB=~shifter;
   Extract();
   shifter=(shifter*2);
   if(shifter>32)
      shifter=1;
   TIM0_counter++;
   if(TIM0_counter>1000)
   {
    TIM0_counter=0;  
    if(blink==1)
    {
       blink=0; 
    }
    else
    {
        blink=1;
    }
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
   }
    
}
void main(void)
{
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 1 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x83;
OCR0=0x00;
// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
PORTB=1;
DDRA=255;
DDRB=255;
#asm("SEI")
while (1)
    {
    // Please write your application code here

    }
}



void Extract(void)
{
    if(blink==1)
    {
        if(shifter==1)
            PORTA=_7segDataCC[s%10];
        else if(shifter==2)
            PORTA=_7segDataCC[s/10];
        else if(shifter==4)
            PORTA=_7segDataCC[m%10]+128;
        else if(shifter==8)
            PORTA=_7segDataCC[m/10];
        else if(shifter==16)
            PORTA=_7segDataCC[h%10]+128;
        else if(shifter==32)
            PORTA=_7segDataCC[h/10];
    }
    else if(blink==0)
    {
        if(shifter==1)
            PORTA=_7segDataCC[s%10];
        else if(shifter==2)
            PORTA=_7segDataCC[s/10];
        else if(shifter==4)
            PORTA=_7segDataCC[m%10];
        else if(shifter==8)
            PORTA=_7segDataCC[m/10];
        else if(shifter==16)
            PORTA=_7segDataCC[h%10];
        else if(shifter==32)
            PORTA=_7segDataCC[h/10];  
    }
}