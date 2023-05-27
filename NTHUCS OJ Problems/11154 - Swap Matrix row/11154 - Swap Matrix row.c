#include<stdio.h>

int main(void)
{
    int matrix[5][5], times, input[2], temp, i, j;

    i=0;
    while(i<5) {
        j=0;
        while(j<5) {
            scanf("%d",&matrix[i][j]);
            j++;
        }
        i++;
    }

    scanf("%d",&times);

    while(times>0){
        scanf("%d%d",&input[0],&input[1]);
        for(j=0; j<5; j++)
        {
            temp = matrix[input[0]][j];
            matrix[input[0]][j] = matrix[input[1]][j];
            matrix[input[1]][j] = temp;
        }
        times--;
    }

    i=0;
    while(i<5) {
        j=0;
        while(j<4) {
            printf("%d ",matrix[i][j]);
            j++;
        }
        printf("%d",matrix[i][j]);
        printf("\n");
        i++;
    }

    return 0;
}
