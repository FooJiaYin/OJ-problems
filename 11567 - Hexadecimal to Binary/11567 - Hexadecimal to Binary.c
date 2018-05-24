#include<stdio.h>

int main(void)
{
    int A, B, sum, i, bin[1000];

    scanf("%x%x", &A, &B);

    sum = A + B;

    for(i=0; sum>0; i++, sum/=2)
        bin[i] = sum%2;

    for(i--; i>=0; i--)
        printf("%d", bin[i]);

    return 0;
}
