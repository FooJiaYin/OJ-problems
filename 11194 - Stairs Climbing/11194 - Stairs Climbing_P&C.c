#include<stdio.h>

long long P(int n,int r)
{
    long long p=1;
    int i;
    if(r==0)return 1;
    for(i=0; i<r; i++)
        p *= n-i;
    return p;
}

long long C(n,r)
{
    if(r>n-r) r=n-r; //avoid overflow of P(n,r)
    if(r==0) return 1;
    return P(n,r)/P(r,r);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        int X;
        scanf("%d", &X);

        int i;
        long long sum=0;
        for(i=0; i<=X/2; i++)
        {
            sum += C(X-i,i);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
