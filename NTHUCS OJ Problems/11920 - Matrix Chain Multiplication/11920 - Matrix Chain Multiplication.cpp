#include "function.h"

Matrix Matrix::operator*(const Matrix &a) const {
    int r = get_size_row();
    int c = a.get_size_col();
    Matrix ans(r, c);
    for(int row_id=0; row_id<get_size_row(); row_id++) {
        for(int col_id=0; col_id<a.get_size_col(); col_id++) {
            int *rowA = get_row(row_id);
            int *colB = a.get_col(col_id);
            ans.arr[row_id][col_id] = 0;
            for(int i=0; i<get_size_col(); i++)
                ans.arr[row_id][col_id] += rowA[i] * colB[i];
			delete [] rowA;
            delete [] colB;
        }
    }
    return ans;
}

Matrix Matrix::operator=(const Matrix &a) {
    size_row = a.size_row;
    size_col = a.size_col;
    arr = a.arr;
    return *this;
}

Matrix MatrixChain::calc(int l, int r) const {
    Matrix ans = *arr[l];
    for(int i=l+1; i<r; i++) {
        ans = ans * *arr[i];
    }
    return ans;
}