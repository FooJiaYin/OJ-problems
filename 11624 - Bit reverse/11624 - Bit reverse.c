#include<stdio.h>

int main(void)
{
    int N, bin[8]={0}, ans=0, i, pow2=0;

    scanf("%d", &N);

    for(i=0; N>0; i++, N/=2)
        bin[i] = N%2;

    for(i=7, pow2=1; i>=0; i--, pow2*=2)
        ans += bin[i]*pow2;

    printf("%d\n", ans);

    return 0;
}
