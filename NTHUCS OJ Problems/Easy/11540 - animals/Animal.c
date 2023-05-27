#include<stdio.h>

int main(void)
{
    int A, B, C, x, y, z;
    /* A is the total number of stomachs, B is the total number of legs, C is the total number of tails, */

    scanf("%d %d %d", &A, &B, &C);

    y = A + C - B; //cows
    z = B/2 - C - y; //alpacas
    x = C - y - z; //chickens

    printf("%d %d %d", x, y, z);

    return 0;
}

