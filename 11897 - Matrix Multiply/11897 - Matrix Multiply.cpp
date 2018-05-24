#include "function.h"

int calculate(Matrix A, Matrix B) {
    int Sum = 0;
    for(int row=0; row<A.get_size(); row++) {
        for(int col=0; col<B.get_size(); col++) {
            int *rowA = A.get_row(row);
            int *colB = B.get_column(col);
            for(int i=0; i<A.get_size(); i++){
                Sum += rowA[i]*colB[i];
            }
            A.remove(rowA);
            B.remove(colB);
        }
    }
    return Sum;
}