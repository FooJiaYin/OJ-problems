#include<stdio.h>
#include<string.h>

int main(void)
{
    char input[1000];
    int L, i, j;

    scanf("%s", &input);
    L = strlen(input);

    for(i=1; i<=L; i++)
    {
        for(j=i; j<=L-1; j++)
            printf("%c", input[j]);
        for(j=0; j<i; j++)
            printf("%c", input[j]);
        printf("\n");
    }
    return 0;
}
