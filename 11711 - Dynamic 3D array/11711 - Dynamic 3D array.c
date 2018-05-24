#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    unsigned ***arr_1;
    unsigned **arr_2;
    unsigned *arr_3;

    arr_3 = (unsigned *)malloc(sizeof(unsigned)*n*m*k);
    arr_2 = (unsigned *)malloc(sizeof(unsigned*)*n*m);
    arr_1 = (unsigned *)malloc(sizeof(unsigned**)*n);

    int i, j;
    for(i=0; i<n; i++) {
        arr_1[i] = arr_2 + i*m;
        for(j=0; j<m; j++) {
            arr_1[i][j] = arr_3 + (i*m +j)*k;
        }
    }

    return arr_1;
}

void delete_3d_array(unsigned ***arr) {
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
