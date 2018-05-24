#include<stdio.h>
char map[30][50]={0};
int max_y, x, y;

void Print_Map(int H)
{
    int i,j;
    for(i=0; i<=H+1; i++)
    {
        for(j=0; j<=max_y; j++)
        {
            if(map[i][j]==0) printf(" ");
            else printf("%c", map[i][j]);
        }
        printf("\n");
    }

}

char shoot_up(int C, int H)
{
    //Print_Map(H);
    map[x][y]='*';

    if(x==0)
    {
        if(y>max_y) max_y = y;
        return 'x';
    }
    else if (x==1&&y<C) return 'd';

    else
    {
        x--, y++;
        shoot_up(C, H);
    }
}

char shoot_down(int F, int H)
{
    //Print_Map(H);
    map[x][y]='*';

    if(x==H+1)
    {
        if(y>max_y) max_y = y;
        return 'x';
    }
    else if (x==H&&y<F) return 'u';

    else
    {
        x++, y++;
        shoot_down(F, H);
    }
}

int main(void)
{
    int C, F, H, S;
    char direction;
    scanf("%d %d %d %d %c", &C, &F, &H, &S, &direction);

    int i,j;
    for(i=0; i<C; i++)
        map[0][i]='-';
    for(i=0; i<F; i++)
        map[H+1][i]='-';

    if(C>=F) max_y = C;
    else max_y = F;
    //Print_Map(H);
    x = S, y = 0;

    while(direction!='x')
    {
        if(direction=='u') direction = shoot_up(C, H);
        if(direction=='d') direction = shoot_down(F, H);
    }

    Print_Map(H);

    return 0;
}
