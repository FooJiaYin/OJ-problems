#include<stdio.h>

int main(void)
{
    int a,b,c,d,e,f,SUM;

    scanf("%1d%1d%1d %1d%1d%1d", &a, &b, &c, &d, &e, &f);

    SUM = (a+d)*110000 + (b+e)*1100 + (c+f)*11;

    printf("%d", SUM);

    return 0;
}
