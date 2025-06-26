/*
 * keypad.c
 *
 * Created: 6/26/2025 11:52:51 AM
 * Author: Asus
 */

#include <io.h>
#include <delay.h>
#include <stdint.h>

#define   CO0   ((PIND>>4)&0x01) 
#define   CO1   ((PIND>>5)&0x01)
#define   CO2   ((PIND>>6)&0x01)
#define   CO3   ((PIND>>7)&0x01)
uint8_t keypad(void);


void main(void)
{

DDRD=0x0f; //-> 0000 1111
PORTD=0xff;
while (1)
    {
    // Please write your application code here
    keypad();

    }
}


int8_t keypad(void)
{
    uint8_t row=1;
    int8_t column=-1; 
    uint8_t position=0;
    for(row=0;row<=3;row++)
    {
        PORTD=~(1<<row);  
        if(CO0==0){column=0;}
        if(CO1==0){column=1;} 
        if(CO2==0){column=2;}
        if(CO3==0){column=3;}
        if(column!=-1)   
        {  
          position=row*4+column; 
          return position;
        }
        
        delay_ms(500);

    
    }

return -1;
}