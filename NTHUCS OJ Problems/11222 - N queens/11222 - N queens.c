#include<stdio.h>
int N, count=0;
int board[12][12]={0};

void display(void)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%d", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int check(int row, int col) //check if contradicts with queen before
{
    int i;
    for(i=0; i<row; i++)
        if(board[i][col]||(col-i>0&&board[row-i-1][col-i-1])||(col+i+1<N&&board[row-i-1][col+i+1]))
            return 0;

    return 1;
}

void place(int row)
{
    int col;
    if(row==N) count++;
    else
    {
        for(col=0; col<N; col++)
            if(check(row, col))
            {
                board[row][col]=1;
                place(row+1);
                board[row][col]=0; //back and continue to next probability
            }
    }
}

int main(void)
{
    scanf("%d", &N);
    place(0);
    printf("%d", count);
    return 0;
}
