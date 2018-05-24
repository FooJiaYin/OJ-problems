#include<stdio.h>

int main(void)
{
    int N, X, Y, Z, both, CSonly;

    scanf("%d %d %d %d", &N, &X, &Y, &Z);

    both = X + Y + Z - N; //who take both CS13550* and CL10100*
    CSonly = N - Y - Z; //who take CS13550* but not CL10100*

    printf("%d %d", both, CSonly);

    return 0;
}
