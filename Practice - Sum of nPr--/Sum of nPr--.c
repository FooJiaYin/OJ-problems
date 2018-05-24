#include<stdio.h>

long long nPr(int n, int r)
{
    long long ans;
    if(n==r) return r+1;
    return 1+n*nPr(n-1,r);
}

long long nPr_print(int n, int r)
{
    long long ans;
    if(n==r)
    {
        printf("%d", n);
        return r+1;
    }
    printf("%d(1+", n);
    ans=1+n*nPr_print(n-1,r);
    printf(")");
    return ans;
}

int main(void)
{
    int N; int R;

    printf("n=");
    while(scanf("%d", &N)!=EOF)
    {
        printf("r=");
        scanf("%d", &R);
        printf("\n=%lld\n", (nPr_print(N, N-R+1)-1));
        printf("%lld\n", 53*(nPr(N, N-R+1)-1));
        printf("n=");
    }

    return 0;
}
