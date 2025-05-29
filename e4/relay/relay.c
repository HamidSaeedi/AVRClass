/*
 * relay.c
 *
 * Created: 5/15/2025 6:40:13 PM
 * Author: Asus
 */

#include <io.h>
#include <delay.h>
#include <stdint.h>
void main(void)
{
DDRA=0x01;

while (1)
    {
    // Please write your application code here   
    PORTA=~PINA;
    delay_ms(3000);
    }
}
