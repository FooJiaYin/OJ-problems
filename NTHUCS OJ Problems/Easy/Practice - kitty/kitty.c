#include<stdio.h>
#include<stdlib.h>
void kitty();

int main()
{
    int k;
    scanf("%d",&k);
    kitty(k);
    return 0;
}

void kitty(int k)
{
    int i;
    for(i=0;i<k;i++)
    printf("Hello Kitty\n");
}
