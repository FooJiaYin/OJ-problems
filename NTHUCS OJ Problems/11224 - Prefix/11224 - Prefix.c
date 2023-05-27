#include<stdio.h>
#include<ctype.h>

float calculate(void);

int main(void)
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        float ans;
        ans = calculate();
        if (((int)(ans*100))%100) printf("= %.1f\n", ans);
        else printf("= %.0f\n", ans);
    }
    return 0;
}

float calculate(void)
{
    char input;
    float ans, op1, op2;
    scanf(" %c", &input);

    if(input==' ') calculate();

    if(input=='+')
    {
        printf("( ");
        op1 = calculate();
        printf("+ ");
        op2 = calculate();
        ans = op1 + op2;
        printf(") ");
    }
    if(input=='-')
    {
        printf("( ");
        op1 = calculate();
        printf("- ");
        op2 = calculate();
        ans = op1 - op2;
        printf(") ");
    }
    if(input=='*')
    {
        printf("( ");
        op1 = calculate();
        printf("* ");
        op2 = calculate();
        ans = op1 * op2;
        printf(") ");
    }
    if(input=='/')
    {
        printf("( ");
        op1 = calculate();
        printf("/ ");
        op2 = calculate();
        ans = op1 / op2;
        printf(") ");
    }

    if(isdigit(input))
    {
        ungetc(input, stdin);
        scanf("%f", &ans);
        printf("%.0f ", ans);
    }

    return ans;
}
