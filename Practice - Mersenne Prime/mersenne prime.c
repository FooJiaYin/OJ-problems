#include<stdio.h>

int main(void)
{
    long n,m,i=1,divisor;

    for (n=4;i<=8;n*=2)
    {
        for (divisor=2; divisor<=n-1 && (n-1)%divisor>0; divisor++);
        if (n-1==divisor)
        {
            printf("%ld\n",n-1);
            i++;
        }
    }

    return 0;

}
