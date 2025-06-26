

#include <io.h>
#include <stdint.h>
#include <delay.h>
uint8_t _7segDataCC[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};  
uint8_t i=0;
void main(void)
{
DDRD=0xff;
while (1)
    {
    // Please write your application code here
     for(i=0;i<=9;i++)
     {
        PORTD= _7segDataCC[i];   
        delay_ms(300);
     } 
    }
}
