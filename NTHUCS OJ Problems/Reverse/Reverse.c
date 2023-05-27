#include<stdio.h>

int main(void)
{
    long input, REVERSE, n;
    int digit[10]={0}, i;

    scanf("%ld", &input);

    /* Get numbers */
    for(i=0, n=1; i<=10; n*=10, i++)
        digit[i]=(input/n)%10;

    /* Find i = number of digits */
    for(i=10;!(digit[i]);i--);

    /* Reverse and sum up */
    for(n=1, REVERSE=0; i>=0; n*=10, i--)
        REVERSE += digit[i]*n;

    printf("%d",REVERSE);

    return 0;
}

