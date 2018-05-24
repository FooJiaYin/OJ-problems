#include<stdio.h>

long NthSmallestPrime(long x, int n)
{
    int i=1;
    long divisor;

    while(i<=n)
    {
        for(divisor=2; x%divisor > 0 && divisor*divisor<x; divisor++);
        if((x%divisor > 0 || x==2) && x>1)
            i++;
        x++;
    }

    return x-1;
}

int main(void)
{
    int T, n, i;
    long x, p[100]= {0};

    scanf("%d", &T);

    for(i=0; i<T; i++)
    {
        scanf("%ld %d", &x, &n);
        p[i]= NthSmallestPrime(x, n);
    }

    for(i=0; i<T; i++)
        printf("%d\n", p[i]);

    return 0;
}
