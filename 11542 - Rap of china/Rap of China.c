#include<stdio.h>

int main(void)
{
    long long A, B, x, y;
    /* A is Total number of gold chains and B is Total number of silver rings. */

    scanf("%lld %lld", &A, &B);

    x = 3*A - 2*B; //PG One
    y = 3*B - 4*A; // GAI

    printf("%lld %lld", x, y);

    return 0;
}
