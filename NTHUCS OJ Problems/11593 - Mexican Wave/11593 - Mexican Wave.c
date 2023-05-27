#include<stdio.h>

void PrintWave(int n, int m, int t)
{
    int sitno1=0, standno=0, sitno2=0, i=n;

    for(sitno1=1; sitno1<=t-m && sitno1<=n; sitno1++)
        printf("%c", '-');

    for(standno=1; standno<=m && standno<=t && standno<=m+n-t; standno++)
        printf("%c", '^');

    for(sitno2=1; sitno2<=n-t; sitno2++)
        printf("%c", '-');

    printf("\n");
}

int main(void)
{
    int T, m[100]={0}, n[100]={0}, t[100]={0}, i;

    scanf("%d", &T);

    for(i=0; i<T; i++)
        scanf("%d %d %d", &n[i], &m[i], &t[i]);

    for(i=0; i<T; i++)
        PrintWave(n[i], m[i], t[i]);

    return 0;

}
