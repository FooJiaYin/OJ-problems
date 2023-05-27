#include <stdio.h>

int main(void)
{
    int bit[65];
    int i, j;
    unsigned long long x;

    scanf("%llu", &x);
    i = 0;

    for(i=0; x>0; i++,x/=2)
        bit[i]=x%2;

    /* Invert back to normal*/
    for(j=i-1; j>=0; j--)
        printf("%d",bit[j]);
    printf("\n");

    return 0;
}
