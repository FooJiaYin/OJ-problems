#include<stdio.h>>

int main(void)
{
    int a, b, c, d, e, f;
    double sum;

    scanf("%1d%1d%1d.%1d%1d%1d", &a, &b, &c, &d, &e, &f);

    sum = (a+c)*101 + 2*b*10 + (f+d)*0.101 + 2*e*0.01;

    printf("%.3lf", sum);

    return 0;
}
