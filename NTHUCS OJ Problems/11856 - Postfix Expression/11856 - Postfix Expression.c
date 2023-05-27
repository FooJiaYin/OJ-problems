#include <stdio.h>
#include <string.h>
#include <ctype.h>

int now;

int operate(char op[], int number[])
{
    now--;
    int op1, op2;
    if(op[now]){
        switch(op[now]) {
        case '+' :
            op2 = operate(op, number);
            op1 = operate(op, number);
            return op1 + op2;
        case '-' :
            op2 = operate(op, number);
            op1 = operate(op, number);
            return op1 - op2;
        case '*' :
            op2 = operate(op, number);
            op1 = operate(op, number);
            return op1 * op2;
        case '/' :
            op2 = operate(op, number);
            op1 = operate(op, number);
            return op1 / op2;
        }
    }
    else if(number[now]) {
        return number[now];
    }
}

int main(void)
{
    int number[45] = {0};
    char op[45] = {0};
    int id = 0;
    char input;
    while(scanf("%c", &input)!=EOF){
        
        if(isdigit(input)) {
            ungetc(input, stdin);
            scanf(" %d", &number[id++]);
        }
        else if(input == '+' || input == '-' || input == '*' || input == '/')
            op[id++] = input;
    }

    now = id;
    printf("%d", operate(op, number));
    return 0;
}
