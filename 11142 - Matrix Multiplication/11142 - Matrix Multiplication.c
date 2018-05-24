#include<stdio.h>

int A[120][120]={0}, B[120][120]={0};
long long M[120][120]={0};

int main(void)
{
    int n, m, p;
    int i, j, k;

    while(scanf("%d %d %d", &n, &m, &p) != EOF)
    {
        /* Scan Matrix A */
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                scanf("%d", &A[i][j]);
        }

        /* Scan Matrix B */
        for(i=0; i<m; i++)
        {
            for(j=0; j<p; j++)
                scanf("%d", &B[i][j]);
        }

        /* Multiplication */
        for(i=0, j=0, k=0; i<n; i++)
        {
            for(j=0; j<p; j++)
            {
                M[i][j]=0;
                for(k=0; k<m; k++)
                    M[i][j]+=A[i][k]*B[k][j];

                if(j<p-1) printf("%lld ", M[i][j]);
            }
            printf("%lld\n", M[i][j-1]);
        }
        printf("\n");
    }

    return 0;
}
