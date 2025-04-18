#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main()
{
    counter();
    return 0;
}



void counter(void)
{
    uint16_t counter=0;
    printf("%d\n",counter);
    for(counter=1;counter<=256;counter=counter*2)
    {
        printf("%d\n",counter);
    }
}
