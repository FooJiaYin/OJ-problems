#include<stdio.h>

int main(void)
{
    int input[5];
    float SUM;

    scanf("%1d%1d.%1d%1d%1d", &input[0], &input[1], &input[2], &input[3], &input[4]);

    SUM = input[2]*100 + (input[0]+input[3])*10 + (input[1]+input[4]) + (input[2]+input[0])/10.0 + (input[3]+input[1])/100.0 + input[4]/1000.0;

    printf("%.3f", SUM);

    return 0;
}

