#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t PORTD=0xfd;
int main()
{

    printf("%d\n",((PORTD >> 1)&(0x01)));
    return 0;
}
