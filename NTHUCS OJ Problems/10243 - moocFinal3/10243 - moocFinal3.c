#include <stdio.h>

int main(void)
{
    int size;
    scanf("%d", &size);
    int matrix[size][size];
    int max[size-2][size-2];

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            scanf(" %d", &matrix[i][j]);

    for(int i=0; i<size-2; i++) {
        for(int j=0; j<size-2; j++) {
            max[i][j] = 0;
            for(int x=0; x<3; x++)
                for(int y=0; y<3; y++)
                    if(max[i][j] < matrix[i+x][j+y])
                        max[i][j] = matrix[i+x][j+y];
        }
    }
    for(int i=0; i<size-2; i++) {
        for(int j=0; j<size-3; j++) {
            printf("%d ", max[i][j]);
        }
        printf("%d\n", max[i][size-3]);
    }
    return 0;
}
