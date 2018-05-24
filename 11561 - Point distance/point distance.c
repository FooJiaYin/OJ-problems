#include<stdio.h>

int main(void)
{
    int x1,y1,x2,y2,X,Y;
    double m,c,distance;

    scanf("(%d,%d)", &x1, &y1);
    scanf(" (%d,%d)", &x2, &y2);
    scanf("  (%d,%d)", &X, &Y);

    //y - mx + c = 0

    m = (y2-y1)/((x2-x1)*1.0);
    c = m*x1 - y1*1.0;
    distance = (Y - m*X + c)*(Y - m*X + c)/(1 + m*m);

    printf("%.2f\n", distance);

    return 0;
}
