#include<stdio.h>

int main(void)
{
    int x, y, A, B;

    scanf("%d %d",&A, &B);

    x = (A - B/9)/2;
    y = (A + B/9)/2;

    printf("%d%d", x, y);

    return 0;
}
