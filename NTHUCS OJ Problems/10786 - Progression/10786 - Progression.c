#include<stdio.h>

int main(void)
{
    int num1, num2, num3, num4, num5;

    scanf("%d %d %d", &num2, &num3, &num4);

    /* Arithmetic Progression */
    if (num3-num2 == num4-num3)
    {
        num1 = num2+num2-num3;
        num5 = num4+num4-num3;
    }

    /* Arithmetic Progression */
    else if (num3*num3 == num4*num2)
    {
        num1 = num2*num2/num3;
        num5 = num4*num4/num3;
    }

    printf("%d %d", num1, num5);

    return 0;
}
