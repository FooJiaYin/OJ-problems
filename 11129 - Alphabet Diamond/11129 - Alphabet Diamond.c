#include<stdio.h>
#define SPACE "                            "

void PrintLine(int layer, int n)
{
    int i;
    printf("%.*s", layer-n-1, SPACE);
    for(i=0;i<n;i++)
        printf("%c",'A'+i);
    for(i=n;i>=0;i--)
        printf("%c",'A'+i);
    printf("\n");

    return;
}

int main(void)
{
    int layer, n;

    scanf("%d", &layer);

    printf("%.*sA\n", layer-1, SPACE);

    for(n=1;n<=layer-1;n++)
        PrintLine(layer,n);

    for(n-=2;n>=0;n--)
        PrintLine(layer,n);

    return 0;
}
