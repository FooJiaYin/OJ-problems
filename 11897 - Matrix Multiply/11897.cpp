#include "function.h"
using namespace std;

int **create_matrix(int n) {
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    return arr;
}

void read_matrix(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0 ;j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    int **A = create_matrix(n);
    read_matrix(A, n);
    Matrix MA(n, A);
    int **B = create_matrix(n);
    read_matrix(B, n);
    Matrix MB(n, B);
    cout << calculate(MA, MB) << '\n';
}