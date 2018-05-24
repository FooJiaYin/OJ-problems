#include <stdio.h>
#include <stdint.h>
#include "function.h"

void Print(int m, int n, int matrix[][500] ) {
    int i;
    for (i = 0; i < m; i++ ) {
        int j;
        for (j = 0; j < n; j++ ) {
            printf("%d%c", matrix[i][j], " \n"[j==n-1] );
        }
    }
}

int32_t main(){
    int matrix[500][500];
    int row, col;
    scanf("%d %d", &row, &col);
    int i;
    for (i = 0; i < row; i++ ) {
        int j;
        for (j = 0; j < col; j++ ) {
            scanf("%d", &matrix[i][j]);
        }
    }
    Transpose( &row, &col, matrix);
    Print( row, col, matrix );
    return 0;
}
