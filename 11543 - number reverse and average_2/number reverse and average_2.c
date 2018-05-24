#include<stdio.h>

int main(void)
{
    int n, a, b, c;
    float sum;

    scanf("%d", &n);

    a = n/100,
    b = n/10 - a*10;
    c = n%10;
    sum = (c*100+b*10+a+n);

    printf("%.1f", sum/2);

    return 0;
}
