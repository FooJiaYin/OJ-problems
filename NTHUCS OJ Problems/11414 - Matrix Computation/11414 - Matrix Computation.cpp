#include <iostream>
#include "function.h"
using namespace std;

Matrix::Matrix() : matrix_size{0}, matrix{} {}
Matrix::Matrix(const int size, const int data[50][50]) : matrix_size{size} {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            matrix[i][j] = data[i][j];
        }
    }
}

Matrix Matrix::row( const int row1, const int row2) const {
    Matrix ans(matrix_size, matrix);
    for(int i=0; i<matrix_size; i++) {
        ans.matrix[row1][i] = matrix[row2][i];
        ans.matrix[row2][i] = matrix[row1][i];
    }
    return ans;
}

Matrix Matrix::rotate90() const {
    Matrix ans;
    ans.matrix_size = matrix_size;
    for(int i=0; i<matrix_size; i++) {
        for(int j=0; j<matrix_size; j++) {
            ans.matrix[i][j] = matrix[matrix_size-j-1][i];
        }
    }
    return ans;
}

Matrix Matrix::rotatecounter90() const {
    Matrix ans;
    ans = this->rotate90().rotate90().rotate90();
    return ans;
}

void Matrix::symmetric() const {
    for(int i=0; i<matrix_size; i++) {
        for(int j=i+1; j<matrix_size; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                cout << "no" << endl;
                return;
            }
        }
    }
    cout << "yes" << endl;
}

void Matrix::output() const {
    for(int i=0; i<matrix_size; i++) {
        for(int j=0; j<matrix_size-1; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << matrix[i][matrix_size-1] << endl;
    }
}