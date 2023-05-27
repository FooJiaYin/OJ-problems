#include<stdio.h>

int main(void)
{
    int width, length, height;
    unsigned long price;

    scanf("%d %d %d", &width, &length, &height);
    price = (width*length + length*height + height*width)*2*4;
    printf("The sell price of the box is %d dollars.\n", price);

    return 0;
}
