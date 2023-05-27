#include<stdio.h>
#include<stdlib.h>

long long V[10020];

int compare (const void *a, const void *b)
{
    if(*(long long *)a > *(long long *)b) return 1;
    else if(*(long long *)a ==*(long long *)b) return 0;
    else return -1;

    /* compare is int. Cannot use return(*(long long *)a - *(long long *)b), overflow could occur*/
}

int main(void)
{
    int T, n, i;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%lld", &V[i]);

        qsort(V, n, sizeof(long long), compare);

        for(i=0; i<n-1; i++)
            printf("%lld ", V[i]);
        printf("%lld\n", V[i]);

    }
    return 0;
}
