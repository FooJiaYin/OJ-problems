#include<stdio.h>

int main(void)
{
    int L, W, H;
    unsigned long V, SA;

    scanf("%d %d %d", &L, &W, &H);

    V = L*W*H;
    SA = (L*W + W*H + H*L)*2;

    printf("%d %d", V, SA);

    return 0;
}
