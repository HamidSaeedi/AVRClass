/*
 * kl.c
 *
 * Created: 5/22/2025 5:06:08 PM
 * Author: Asus
 */

#include <io.h>
#include <stdint.h>
#include <stdio.h>
#include <delay.h>
#include <alcd.h>

#define C0 ((PIND>>4)&0X01) 
#define C1 ((PIND>>5)&0X01) 
#define C2 ((PIND>>6)&0X01) 
#define C3 ((PIND>>7)&0X01) 
char lcd_buffer[32];
char layout[16]={'7','8','9','/','4','5','6','*','1','2','3','-','O','0','=','+'};
void keypad(void);
void main(void)
{

DDRD=0x0f; //input and out put 4 pin LSB output 4 pin MSB input
PORTD=0xf0; // enable pull up inputs pins.
lcd_init(16);
while (1)
    {
      keypad();

    }
}


void keypad(void)
{
   int8_t row=0,column=-1,pos=0;
   for(row=0;row<4;row++)
   {
    PORTD=~(1<<row);
    if(C0==0){column=0;} 
    if(C1==0){column=1;}
    if(C2==0){column=2;}
    if(C3==0){column=3;}
    if(column!=-1)
    {
    pos=row*4+column;
    sprintf(lcd_buffer,"%c",layout[pos]);
    lcd_puts(lcd_buffer); 
    column=-1;
    while(C0==0){}
    while(C1==0){}
    while(C2==0){}
    while(C3==0){}
    }
    delay_ms(200);
   } 
}