#include<stdio.h>

int main(void)
{
    int N, minimum;

    scanf("%d", &N);
    minimum = N-(N-1)/3;
    printf("%d\n", minimum);

    return 0;
}
