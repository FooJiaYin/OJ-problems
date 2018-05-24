#include<stdio.h>


int main()
{
    int w,l,h;
    long totalarea;
    scanf("%d %d %d",&w,&l,&h);
    totalarea=(w*l+w*h+l*h)*2;
    printf("The sell price of the box is %d dollars.\n",totalarea*4);

    return 0;
}
