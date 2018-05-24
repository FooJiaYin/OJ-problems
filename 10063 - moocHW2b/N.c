#include<stdio.h>

int main(void)
{
    int N, i, j, bf, af;

    scanf("%d", &N);
    i = (N-2); j = 0;

    /* first line */
    printf("  2 -1");
    for(i=1; i<=(N-2); i++)
        printf("  0");
    printf("\n");

    /* Second line and below */
    for(i=(N-2),j=0; i>0; i--, j++)
    {
        for(bf=0; bf<j; bf++) //zeros before -1  2 -1
            printf("  0");

        printf(" -1  2 -1");

        for(af=0; af<(i-1); af++) //zeros after -1  2 -1
            printf("  0");

        printf("\n");
    }

    /* last line */
    for(j=(N-2); j>0; j--)
        printf("  0");
    printf(" -1  2\n");

    return 0;
}
