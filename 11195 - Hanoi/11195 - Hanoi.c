#include <stdio.h>
#include "function.h"
void hanoi(int n, char A, char B, char C)
{
    if(n<=0) return;
    hanoi(n-1, A, B, C);
    printf("%d\n", n);
    hanoi(n-1, A, B, C);
}
