/*
 * code.c
 *
 * Created: 6/12/2025 6:31:43 PM
 * Author: Asus
 */

#include <io.h>

interrupt [10] void TIMER0 (void)
{

} 


void main(void)
{

TCCR0|=(1<<0)|(1<<2);
TIMSK|=(1<<TOIE0) ;

#asm("SEI")
while (1)
    {
    // Please write your application code here

    }
}
