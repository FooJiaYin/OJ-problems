#include<stdio.h>

int main(void)
{
    int a,b,c;
    char digit1, digit2, digit3;

    scanf("%1d%1d%1d", &a, &b, &c);

    digit1 = ((a+1)%2)*'A' + (a%2)*'B';
    digit2 = ((b+1)%2)*'C' + (b%2)*'D';
    digit3 = ((c+1)%2)*'E' + (c%2)*'F';

    printf("%c%c%c",digit1, digit2, digit3);

    return 0;
}
