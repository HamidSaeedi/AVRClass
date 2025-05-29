/*
 * seg.c
 *
 * Created: 5/8/2025 7:08:47 PM
 * Author: Asus
 */

#include <io.h>
#include <stdint.h>
#include <delay.h>
uint8_t _7segDataCC[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//uint8_t i=0;
//uint16_t j=0;
uint32_t MyNumber=1379;
void Extract(uint32_t num);
void main(void)
{
 DDRA=0xff;  
 DDRB=0xff;
while (1)
{
    Extract(MyNumber);
}

}
void Extract(uint32_t num)
{
    uint32_t temp=0;  
    uint16_t count=8;
    temp=num;
    
    while(temp!=0)
    {                
        PORTB=count;
        PORTA=~(_7segDataCC[temp%10]);
        temp=temp/10;   
        count=count/2;  
        delay_ms(5);
        
    }
}