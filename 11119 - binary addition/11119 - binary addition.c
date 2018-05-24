#include<stdio.h>

int main(void)
{
    int input, add1, bin1[10]={0}, bin2[10]={0}, i, j;

    scanf("%d", &input);

    /*transform into binary representation*/
    for(i=0, add1=input+1; add1>0; input/=2, add1/=2, i++)
    {
        bin1[i] = input%2;
        bin2[i] = (add1)%2;
    }

    for(j=i-1; j>=0; j--)
        printf("%d", bin2[j]);

    /* Calculate carries */
    for(j=0; i>=0; i--)
        if(bin1[i]==1 && bin2[i]==0)
            j++;

    printf(" %d",j) ;

    return 0;
}
