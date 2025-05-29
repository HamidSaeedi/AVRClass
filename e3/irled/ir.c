/*
 * ir.c
 *
 * Created: 5/8/2025 6:07:42 PM
 * Author: Asus
 */

#include <io.h>
#include <stdint.h>
#include <delay.h>

void main(void)
{
DDRA=0x0d;
PORTA=0x01;
while (1)
    {    
    
    if(((PINA)&(0x03))==0x03)
    {
        PORTA=(((PINA)|0x04)&(~(0x08)));  
        
    } 
    
    else
    {
        PORTA=(((PINA)|0x08)&(~(0x04)));
    } 
      
    delay_ms(100);
    // Please write your application code here

    }
}
