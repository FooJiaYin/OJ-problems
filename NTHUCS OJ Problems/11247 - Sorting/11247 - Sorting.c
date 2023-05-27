#include<stdio.h>
#include<stdlib.h>

int compare (const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort(int a[] , int len)
{
    qsort (a, len, sizeof(int), compare);
}

void show_the_array(int a[] , int len)
{
    int i;
    for (i=0; i<len-1; i++)
        printf("%d ", a[i]);
    printf("%d", a[i]);
}

int main(void)
{
    int i,N;
    scanf("%d",&N);
    int *S = malloc(sizeof(int)*N);
    for(i=0;i<N;i++)scanf("%d",S+i);
    sort(S,N);
    show_the_array(S,N);
    return 0;
}
