#include<stdio.h>
int matrix[520][520]={0};

int main(void)
{
    int N, i, j;
    scanf("%d", &N);

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            if(i%2==0 && j%2)
                scanf("%d", &matrix[i+1][j-1]);
            else if(i%2 && j%2==0)
                scanf("%d", &matrix[i-1][j+1]);
            else
                scanf("%d", &matrix[i][j]);
        }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N-1; j++)
            printf("%d ", matrix[i][j]);
        printf("%d\n", matrix[i][j]);
    }

    return 0;
}
