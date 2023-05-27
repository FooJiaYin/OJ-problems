#include <stdio.h>

int operate(void)
{
    char input;
    int op1, op2;
    scanf(" %c", &input);
    switch(input) {
        case '+' :
            op1 = operate();
            op2 = operate();
            return op1 + op2;
        case '-' :
            op1 = operate();
            op2 = operate();
            return op1 - op2;
        default :
            ungetc(input, stdin);
            scanf(" %d", &op1);
            return op1;
    }
}

int main(void)
{
    printf("%d", operate());
    return 0;
}