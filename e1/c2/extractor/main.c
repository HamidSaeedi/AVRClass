#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int32_t MyNum=-345;
int main()
{
    extractor(MyNum);
    return 0;
}



void extractor(int32_t num)
{
    int32_t temp=0;
    if(num>0)
    {
        temp=num;
        printf("+\n");
        while(temp>0)
        {
            printf("%d\n",temp%10);
            temp=temp/10;
        }
    }
    if(num < 0)
    {
        temp=num*(-1);
        printf("-\n");
        while(temp>0)
        {
            printf("%d\n",temp%10);
            temp=temp/10;
        }
    }
}
