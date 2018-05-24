#include<stdio.h>

int main(void)
{
    int X, Y, digit[8], i=0;

    scanf("%d %d", &X, &Y);

    for(i=0;i<Y;i++,X/=3)
        digit[i] = X%3;

    for(i=1;i<=Y;i++)
        printf("%d",digit[Y-i]);
    printf("\n");

    return 0;
}
