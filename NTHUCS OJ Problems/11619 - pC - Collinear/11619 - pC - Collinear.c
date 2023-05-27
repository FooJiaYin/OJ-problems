#include<stdio.h>

int main(void)
{
    int T, N;

    scanf("%d", &T);
    //printf("%d ", T);
    while(T--)
    {
        long long x[110]={0}, y[110]={0};
        int collinear=0, point3=0, point4=0;
        int i, j, k;

        scanf("%d", &N);

        for(i=0; i<N; i++)
            scanf("%lld %lld", &x[i], &y[i]);

        for(i=0; i<N; i++)
        {
            for(j=i+1, collinear=0; j<N; j++)
            {
                for(k=j+1, collinear=0; k<N; k++)
                {
                    if((y[i]-y[j])*(x[j]-x[k]) == (y[j]-y[k])*(x[i]-x[j]))
                        collinear++; //no. of points in this line
                }
                if (collinear==2) point4++;
                if (collinear==1) point3++;
            }
        }
        printf("%d\n", point3-point4);
    }

    return 0;
}
