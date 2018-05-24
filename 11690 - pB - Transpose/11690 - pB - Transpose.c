#include<stdio.h>
#include"function.h"

void Transpose(int* row, int* col, int matrix[][500])
{
    /* Exchange the value of row and column to avoid error in Print()*/
    int p = *row;
    *row = *col;
    *col = p;

    int big;
    if (*row>=*col) big = *row;
    else big = *col;

    int i; int j;
    for(i=0; i<big; i++)
        for(j=i; j<big; j++)
        {
            int temp;
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
}
