#include <iostream>
class Matrix {
private:
    int size;
    int **arr;
    int get_count;
public:
    Matrix(int n, int **data) {
        size = n;
        arr = data;
        get_count = 0;
    }
    int *get_row(int row) {
        int *tmparr = new int[size];
        for (int i = 0; i < size; i++) {
            tmparr[i] = arr[row][i];
        }
        get_count++;
        return tmparr;
    }
    int *get_column(int col) {
        int *tmparr = new int[size];
        for (int i = 0; i < size; i++) {
            tmparr[i] = arr[i][col];
        }
        get_count++;
        return tmparr;
    }
    int get_size() {
        return size;
    }
    void remove(int *array) {
        delete[] array;
        get_count--;
    }
    ~Matrix() {
        if (get_count != 0) {
            std::cout << "[ERROR] something not recylced!\n";
        }
    }
};

int calculate(Matrix A, Matrix B);