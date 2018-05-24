#include<stdio.h>

int main(void)
{
    int input[4]={0},N, M, P;
    long PRODUCT;

    scanf("%d", &N);

    M = (N%1000)*10 + N/1000;
    P = (N%10)*1000 + N/10;
    PRODUCT = M*P;

    printf("%ld", PRODUCT);

    return 0;
}
