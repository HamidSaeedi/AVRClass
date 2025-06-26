

#include <io.h>
#include <stdint.h>
#include <delay.h>
uint8_t _7segDataCC[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uint32_t number=323456;  // -> 1/10 -> %=1 /=0 
void shifter(void);
void Extract(uint32_t num);
void main(void)
{
DDRD=255;
DDRB=0x3f;
PORTD=_7segDataCC[3];
while (1)
    {
      shifter();
    }
}


void shifter(void)
{
    uint8_t i=0;
    for(i=1;i<=32;i=i*2)
    {   
        PORTB=~i;
        Extract(number);  
        delay_ms(6000);
    }
}

void Extract(uint32_t num)
{
    uint32_t temp=0;
    temp=num;
    while(temp!=0)
    {
        PORTD=_7segDataCC[temp%10];
        temp=temp/10; 
        delay_ms(1000);
    }    
}