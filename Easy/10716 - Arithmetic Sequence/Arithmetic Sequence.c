#include<stdio.h>

int main(void)
{
    int a, n, d;
    long Tn, Sum ;

    scanf("%d %d %d", &a, &n, &d);

    Tn = a+(n-1)*d;
    Sum = n*(2*a+(n-1)*d)/2;

    printf("%ld %ld", Tn, Sum);

    return 0;
}
