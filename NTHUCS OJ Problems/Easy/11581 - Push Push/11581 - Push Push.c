#include <stdio.h>

int main (void)
{
    int A1, A2, A, B;

    scanf("%3d%1d", &A1, &A2);
    A = A1*10 + A2;
    B = A2*1000 + A1;
    printf("%d", A+B);

    return 0;
}

