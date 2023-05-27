#include<stdio.h>
int tree[3050]={0};

void find_seq(int k, int N)
{
    if(tree[k]==0) return;
    if(k<N) printf("%d ", tree[k]);
    else printf("%d\n", tree[k]);
    find_seq(2*k,N);
    find_seq(2*k+1,N);
}

int main(void)
{
    int i,N;
    scanf("%d", &N);
    for(i=1; i<=N; i++)
        scanf("%d", &tree[i]);
    find_seq(1, N);
    return 0;
}

