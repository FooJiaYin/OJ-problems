#include<stdio.h>

int main(void)
{
    int input, i, divisor, remainder, i_2;

    scanf("%d",&input);

    for (i=1;i<input;i++)
    {
        //printf("%d ",i);
        remainder=1;
        for(divisor = 2;divisor<i && remainder>0;divisor++)
        {
            remainder = i%divisor;
        }
        if (remainder > 0)
        {
            i_2=i;
        }
    }
    printf("%d",i_2);

    return 0;
}

