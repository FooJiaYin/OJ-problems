#include<stdio.h>

typedef struct _point{
    int x, y;
} point;

char map[505][505]={0};
point queue[505*505]={0}; //important!!!
int row, column, found;
unsigned steps, new;

void check(int i, int j)
{
    if(map[i][j]=='F') found = 1;
    else if(i<0 || i>=row || j<0 || j>=column) return;
    else if(map[i][j]=='$') {
        map[i][j] = 'x';
        queue[new].x = i;
        queue[new].y = j;
        new++;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    while(N--){
        scanf("%d %d ", &row, &column);
        unsigned read = 0, end = 0;
        steps = 0, new = 1, found = 0;
        for(int i=0; i<row; i++){
            scanf(" %s", map[i]);
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(map[i][j]=='S') queue[0].x = i, queue[0].y = j;
            }
        }
        for(steps=0; found==0 && new!=end; ++steps){
            end = new;
            for(; read<end && found==0; read++) {
                check(queue[read].x+1, queue[read].y);
                check(queue[read].x-1, queue[read].y);
                check(queue[read].x, queue[read].y+1);
                check(queue[read].x, queue[read].y-1);
            }
        }
        if(found) printf("%u\n", steps);
        else printf("-1\n");
    }

    return 0;
}
