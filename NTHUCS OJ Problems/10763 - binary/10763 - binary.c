#include<stdio.h>
void transform(int left, int right)
{
    if (left+right == 1)
        printf("1");
    else
        printf("0");
}

int main(void)
{
    int input, bin[10]={0}, b[10]={0}, i, j;

    scanf("%d", &input);

    /*transform decimal into INVERTED binary representation*/
    for(i=0; input>0; i++,input/=2)
        bin[i]=input%2;

    /* Invert back to normal*/
    for(j=i-1; j>=0; j--)
        printf("%d",bin[j]);

    printf(" ");

    /*transform A to B */
    transform(bin[0],bin[i-1]); //left-most-digit
    for(i-=2; i>=0; i--)
        transform(bin[i],bin[i+1]);

    return 0;
}
