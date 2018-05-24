#include<stdio.h>

int main(void)
{
    int a[10][10] = {0}, i, j;

    i=0;
    while(i<10){
        j=0;
        while(j<10){
            a[i][j] = i*10 + j;
            ++j;
        }
        ++i;
    }

    i=0;
    while(i<10){
        j = 0;
        while(j<10){
            printf("%3d", a[i][j]);
            ++j;
        }
        printf("\n");
        ++i;
    }

}
