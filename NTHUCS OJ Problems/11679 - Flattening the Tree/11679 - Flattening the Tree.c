#include<stdio.h>
int A[10000]={0};

int find_seq(int k)
{
    if(A[k]==0) return;

    find_seq(2*k);

    if(A[k+1]==0) printf("%d\n", A[k]);
    else printf("%d ", A[k]);

    find_seq(2*k+1);
}

int main(void)
{
    int n, i, j;

    scanf("%d", &n);
    for(i=1; i<=n; i++)
        scanf("%d", &A[i]);

    find_seq(1);

    return 0;
}
