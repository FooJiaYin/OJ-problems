#include<stdio.h>
char map[1020][1020]={0};

void dry_pond(int i, int j)
{
    if(map[i][j]=='~')
    {
        map[i][j]='x'; //avoid walking around the same places
        dry_pond(i,j+1);
        dry_pond(i,j-1);
        dry_pond(i+1,j);
        dry_pond(i-1,j);
    }
}

int main(void)
{
    //char map[100][100]={0};
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf(" %c", &map[i][j]);

    long pond=0;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(map[i][j]=='~')
            {
                pond++;
                dry_pond(i,j);
            }

    printf("%d\n", pond);
}
