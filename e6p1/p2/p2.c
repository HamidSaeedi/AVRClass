

#include <io.h>
#include <delay.h>
#include <stdint.h>


void main(void)
{

DDRA |= (1<<0) | (0<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) |(1<<6) |(1<<7);
PORTA |= (1<<1); 
PORTA &= ~(1<<0) & ~(1<<2) & ~(1<<3) & ~(1<<4) & ~(1<<5)  & ~(1<<6) & ~(1<<7);    // (1 1 1 1 1 1 1 0) & (1 1 1 1 1 0 1 1) & ~(1<<3) &   
    
while (1)
    {
        PORTA ^= (1<<0);
        delay_ms(1000);
        PORTA ^= (1<<0); 
        delay_ms(1000); 
        if(((PINA>>1)&0X01) ==0)                      // X X X X X X 1 X // X X X X X X 0 X  (>>1)->>    0 X X X X X X 1 // 0 X X X X X X 0 & 0X01  0 0 0 0 0 0 0 1   -->
            PORTA |=(1<<2); //LED ON                                                                     0 0 0 0 0 0 0 C -C=0,1 
        else if(((PINA>>1)&0X01)==1)
            PORTA &=~(1<<2); //LED OFF
    }
}
