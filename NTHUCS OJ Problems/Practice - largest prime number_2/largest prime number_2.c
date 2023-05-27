#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,i,j=0;

    scanf("%d",&num);

    for(i=num;i>0 && i>j ;i--)
        for(j=2;j<i && (i%j)!=0;j++);

    printf("%d",j);

    return 0;
}
