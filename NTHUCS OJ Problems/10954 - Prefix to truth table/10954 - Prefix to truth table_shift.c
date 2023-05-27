#include <stdio.h>
#include <stdlib.h>

int now = 0;

int operate(int A, int B, int C, int D, char exp[])
{
    now++;
    if (now <= strlen(exp))
    {
        int op1, op2;
        switch (exp[now-1]) {
        case '|':
            op1 = operate(A, B, C, D, exp);
            op2 = operate(A, B, C, D, exp);
            return op1 || op2; //cannot write `return operate(A, B, C, D, exp) || operate(A, B, C, D, exp);`
        case '&':
            op1 = operate(A, B, C, D, exp);
            op2 = operate(A, B, C, D, exp);
            return op1 && op2; //cannot write `return operate(A, B, C, D, exp) && operate(A, B, C, D, exp);`
        case 'A': return A;
        case 'B': return B;
        case 'C': return C;
        case 'D': return D;
        }
    }
}

int main(void)
{
    char exp[35] = {0};
    scanf("%s", exp);
    for (int i = 0; i < 16; i++) {
        now = 0;
        printf("%d %d %d %d %d\n", (i&8)>>3, (i&4)>>2, (i&2)>>1, i&1, operate((i&8)>>3, (i&4)>>2, (i&2)>>1, i&1, exp));
    }
    return 0;
}