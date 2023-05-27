#include<stdio.h>

int main(void)
{
    int N, M, c, i;
    long long m, f=0;

    scanf("%d %d", &N, &M);
    N++;
    while(N--)
    {
        scanf("%d", &c);
        for(i=N, m=1; i>0; i--)
            m*=M;
        m*=c;
        f+=m;
    }
    printf("%ld\n", f);

    return 0;
}

