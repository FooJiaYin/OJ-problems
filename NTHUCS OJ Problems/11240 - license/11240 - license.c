#include <stdio.h>

int main(void)
{
    int str[5]={0}, HIT[10000]={0};

    int N, i, j, k;
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%1d%1d%1d%1d", &str[0], &str[1], &str[2], &str[3]);

        /* Using bubble sort to rearrange an array A[n] */
        for (k = 4; k > 0; k--) {
            for (j = 1; j < k; j++) {
                if (str[j-1] > str[j]) {
                /* swap A[j-1] A[j] */
                    int temp;
                    temp = str[j-1];
                    str[j-1] = str[j];
                    str[j] = temp;
               }
               //printf("%d%d%d%d\n",str[0], str[1], str[2], str[3]);
            }
        }

        int value;
        value = str[0]*1000 + str[1]*100 + str[2]*10 + str[3];
        HIT[value]++;
    }

    for(i=0; i<10000; i++)
        if(HIT[i]>=2) printf("%04d\n", i);

    return 0;
}

