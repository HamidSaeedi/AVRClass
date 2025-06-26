

#include <io.h> //general avr library
#include <delay.h>
#include <stdint.h>

#define LED_DIR DDRA | (1<<0) 
#define Button_DIR DDRA & (~(1<<1))   
void main(void)
{

            
 LED_DIR;
 Button_DIR;
while (1)
    {
    // Please write your application code here
      
    }
}
