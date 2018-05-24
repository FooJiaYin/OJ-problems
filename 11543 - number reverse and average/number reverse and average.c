#include<stdio.h>

int main(void)
{
    int digit1, digit2, digit3;
    float average;

    scanf("%1d%1d%1d", &digit1, &digit2, &digit3);

    average = (digit1 + digit3)*50.5 + digit2*10;

    printf("%.1f", average);

    return 0;
}
