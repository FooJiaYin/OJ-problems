#include<stdio.h>
#include<string.h>

int main(void)
{
    char A[5], Bi[11];
    int n, i, j, occurrence[10]={0};

    scanf("%s", A);
    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", Bi);
        /* Calculate the Occurrence */
        occurrence[n]=0;
        for(i=0; i<=strlen(Bi)-1; i++)
        {
            for(j=i; j-i<strlen(A)&& Bi[j]==A[j-i]; j++);
            if (j-i==strlen(A)) occurrence[n]++;
        }

        /* Compare Occurrence */
        if (occurrence[n]<occurrence[n+1])
            occurrence[n]=occurrence[n+1];
    }
    printf("%d", occurrence[n+1]);

    return 0;
}
