#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare_string(const void *a, const void *b)
{
    const char **sa = (char**)a;
    const char **sb = (char**)b;
    return strcmp(*sa,*sb);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    while(N) {
        char original[N][55];
        char *sorted[N];
        for(int i=0; i<N; i++) {
            sorted[i] = original[i];
            scanf(" %s", original[i]);
        }

        qsort(sorted, N, sizeof(char*),compare_string);

        for(int i=0; i<N; i++)
            printf("%s\n", sorted[i]);
        printf("\n");
        scanf("%d", &N);
    }
    return 0;
}
