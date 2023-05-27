#include<stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int left[260]={0}, right[260]={0}, overlap=0;
    int i, j;

    for(i=0; i<N; i++)
        scanf("%d %d", &left[i], &right[i]);

    for(i=0; i<N; i++)
        for(j=i+1; j<N; j++)
        {
            if((left[j]>left[i]&&left[j]<right[i])||(left[i]>left[j]&&left[i]<right[j])||right[i]>left[j]&&right[i]<right[j])
                overlap++;
        }
    printf("%d\n", overlap);

    return 0;
}
