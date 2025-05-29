#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>

uint16_t a=25;
float t=2.145;
uint8_t i=0;

int main()
{
    if(a==6)
    {
       printf("condition is true a=6\n");
       a=0;
       printf("now a=0\n");
    }
    else if(a==4)
    {
       printf("condition is true a=4\n");
       a=0;
       printf("now a=0\n");
    }
    else if(a==8)
    {
       printf("condition is true a=8\n");
       a=0;
       printf("now a=0\n");
    }
    else
    {
        printf("else is here\n");
    }

    for(;i<10;)
    {
       printf("** %d\n",i);
       i++;
    }

    while(i<25)
    {
       printf("## %d\n",i);
       i++;
    }







    return 0;
}
