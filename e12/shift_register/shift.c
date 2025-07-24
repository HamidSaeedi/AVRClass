/*
 * shift.c
 *
 * Created: 7/24/2025 7:18:47 PM
 * Author: Asus
 */

#include <io.h>
#include <delay.h>
#include <stdint.h>

#define data PORTB.5 
#define SH_CP PORTB.7
#define OE PORTB.0
void serializer(uint8_t number);
void ClearDisp(void);

uint8_t counter=0;
int8_t counter1=9;
uint8_t _7segDataCC[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void main(void)
{
DDRB=255;
//DDRB |=(1<<6) | (1<<7);
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
while (1)
    {
    // Please write your application code here
    counter++; 
    counter1--;
    if(counter1<0)
        counter1=9;
    if(counter>10)
      counter=0;
    serializer(_7segDataCC[counter]);
    serializer(_7segDataCC[counter1]);  
    delay_ms(500);
    
    }
}

void serializer(uint8_t number)
{
/*
   int ii;    
    for(ii=7;ii>=0;ii--)
    {   
        data=((number>>ii)&0x01); 
        SH_CP=1;
        delay_us(500);
        SH_CP=0; 
        delay_us(500);
    }
    */
        SPDR =number ;
/* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));
    ClearDisp();
}

void ClearDisp(void)
{
    OE=1;
    delay_us(100);
    OE=0;
    delay_us(100); 
    //ST_CP=1;
    //delay_us(100);
    //ST_CP=0;
    
}