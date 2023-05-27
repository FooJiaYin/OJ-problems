#include<stdio.h>

int main(void)
{
    long T;
    scanf("%ld", &T);

    while(T--)
    {
        int Ax0, Ay0, Ax1, Ay1, Bx0, By0, Bx1, By1;
        scanf("%d %d %d %d %d %d %d %d", &Ax0, &Ay0, &Ax1, &Ay1, &Bx0, &By0, &Bx1, &By1);

        if(Ax0>=Bx1 || Bx0>=Ax1 || Ay0>=By1 || By0>=Ay1)
            printf("Do you like WHAT YOU SEE,ASS WE CAN\n");

        else
            printf("BOY NEXT DOOR,DEEP DARK FANTASY\n");
    }

    return 0;
}
