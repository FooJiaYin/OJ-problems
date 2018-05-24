#include<stdio.h>

int main(void)
{
    int a=0, b=0, digit1[6]={0}, digit2[6]={0}, i, i_2, j, m, n;
    double x[7]={0}, y[7]={0}, sum1, sum2, SUM;
    scanf("%d.%d",&a,&b);
    //printf("%d %d\n",a,b);

    /* Get the value for each digit */
    for(i=0, n=1; i<6; i++, n*=10)
    {
        digit1[i] = (a/n)%10;
        digit2[i] = (b/n)%10;
    }

    /* i is the number of digits before decimal point */
    for(i=5; !(digit1[i]); i--);

    /* Calculate the sum */
    for(sum1=0, sum2=0, n=1, j=0, i_2=4-i; i>=0; n*=10, i--, i_2--, j++)
    {
        sum1 += (digit1[j]+digit1[i])*n;
        sum2 += (digit2[j]+digit2[i_2])*n;
    }
    SUM = sum1 + sum2*n/(1000000.0);
    printf("%.*lf", 6-j, SUM);

    return 0;
}

