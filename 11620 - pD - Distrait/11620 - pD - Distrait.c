#include<stdio.h>

int main(void)
{
    int bingo[5][5];
    int T, N, selected;
    int i, j, t, n, flag;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            scanf("%d", &bingo[i][j]);
    }
    scanf("%d", &T);
    for(t=1;t<=T;t++)
    {
        int row[5]={5,5,5,5,5}, column[5]={5,5,5,5,5}, cross1=5, cross2=5;
        int flag = 0;

        scanf("%d", &N);
        for(n=1;n<=N;n++)
        {
            scanf("%d", &selected);
            for(i=0;i<5 && flag!=1;i++)
            {
                for(j=0;j<5 && bingo[i][j]!=selected;j++);
                if (j<5)
                {
                    row[i]--;
                    column[j]--;
                    if(i==j) cross1--;
                    if(i+j==4) cross2--;
                    break;
                }
            }

            if(n>=5 && flag!=1)
            {
                if((row[i] && column[j] && cross1 && cross2)!=1 && flag!=1)
                {
                    printf("Case #%d: %d\n", t, n);
                    flag = 1;
                }
            }
        }
        if(flag!=1)
           printf("Case #%d: Not yet \\(^o^)/\n", t);
    }

    return 0;
}
