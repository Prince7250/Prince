#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]; 
    }
    return matrix;
}

void multiplyMatrices(int **mat1, int **mat2, int **result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; 
    }
    delete[] matrix;
}

void inputMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r1, c1;
    cin >> r1 >> c1;
    int** mat1 = allocateMatrix(r1, c1);
    inputMatrix(mat1, r1, c1);

    int r2, c2;
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Matrix multiplication not possible" << endl;
        freeMatrix(mat1, r1);
        return 0;
    }
    int** mat2 = allocateMatrix(r2, c2);
    inputMatrix(mat2, r2, c2);

    int** result = allocateMatrix(r1, c2);

    multiplyMatrices(mat1, mat2, result, r1, c1, c2);

    displayMatrix(result, r1, c2);

    freeMatrix(mat1, r1);
    freeMatrix(mat2, r2);
    freeMatrix(result, r1);

    return 0;
}
