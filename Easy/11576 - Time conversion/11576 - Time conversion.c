#include<stdio.h>

int main(void)
{
    int hour,minutes;
    scanf("%2d%2d)", &hour,&minutes);

    if (hour>=12)
    {
        hour-=12;
        printf("%02d:%02d p.m.",hour,minutes);
    }
    else
        printf("%02d:%02d a.m.",hour,minutes);

    return 0;
}
