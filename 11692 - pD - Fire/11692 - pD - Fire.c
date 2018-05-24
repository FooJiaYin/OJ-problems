#include<stdio.h>
char map[1030][1030]={0};
int water=0;

void run(int x, int y)
{
    if(map[x][y]=='~') water=1;
    if(water) return;
    else if(map[x][y]=='.'||map[x][y]=='e')
    {
        map[x][y] = 'x';	//avoid turning around at the same place
        run(x+1, y);
        run(x-1, y);
        run(x, y+1);
        run(x, y-1);
    }
    return;
}

int main(void)
{
    int M, N, i, j, e_x, e_y;
    scanf("%d %d", &M, &N);

    /* Read the Map */
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
            scanf(" %c", &map[i][j]);
            if(map[i][j]=='e') e_x=i, e_y=j;
        }

    run(e_x, e_y);

    if(water) printf("Alive!\n");
    else printf("Dead!\n");

    return 0;
}
