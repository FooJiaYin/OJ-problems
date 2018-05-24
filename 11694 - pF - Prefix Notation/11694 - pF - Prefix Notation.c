#include<stdio.h>
#include<ctype.h>

float calculate(void);

int main(void)
{
    printf("%.3f",calculate());
    return 0;
}

float calculate(void)
{
    char op;
    float ans;
    op = getchar() ;

    if(op=='+')
        ans = calculate()+calculate();

    if(op=='-')
        ans = calculate()-calculate();

    if(op=='*')
        ans = calculate()*calculate();

    if(op=='/')
        ans = (float)calculate()/(float)calculate();

    else if(isdigit(op))
    {
        int digit;
        ungetc(op, stdin);
        scanf("%1d", &digit);
        ans = (float)digit;
    }

    return ans;
}
