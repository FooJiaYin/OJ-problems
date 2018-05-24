#include<stdio.h>

int main(void)
{
    int input1[4], input2[4];
    double SUM;

    scanf("%d,%d,%d.%d", &input1[0], &input1[1], &input1[2], &input1[3]);
    scanf("%d,%d,%d.%d", &input2[0], &input2[1], &input2[2], &input2[3]);

    SUM = (input1[0]+input2[0])*1000000 + (input1[1]+input2[1])*1000 + (input1[2]+input2[2]) + (input1[3]+input2[3])/1000.0;

    printf("%.3f", SUM);

    return 0;
}
