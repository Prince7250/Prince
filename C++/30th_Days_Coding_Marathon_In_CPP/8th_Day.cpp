//1) In C you can pass parameters to a function either by value or by reference. Changes made to variables passed by reference persists after the function. Hence you can pass any number of parameters as reference, which you want to return from function.

// Complete the function given below which takes several parameters and store the minimum, maximum & sum of array in passed pointer variables, so that it can be used in main function.

// void multiReturnArray(int *a, int size, int *min, int *max, int *sum)
// {
//      *min = a[0];
//     *max = a[0];
//     sum = 0;
//      for(int i = 0; i < size; i++){
//          if(*min > *a[i]){
//              *min = *a[i];
//          }
//          if(*max < *a[i]){
//              *max = *a[i];
//          }
//          *sum += *a[i]
//      }
 
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, i;
//     cin >> n;
//     int arr[n];
//     for (i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int min = arr[0], max = arr[0], sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (min > arr[i])
//         {
//             min = arr[i];
//         }
//         if (max < arr[i])
//         {
//             max = arr[i];
//         }
//         sum += arr[i];
//     }
//     cout<<min<<" "<<max<<" "<<sum<<endl;    
//     return 0;
// }

//2) Dynamic allocate two matrices and then find out the multiplication in third matrix bookmark_border
// Write is a program to perform dynamic memory allocation (DMA) through a separate function and multiply two matrices using a separate function as well. The program takes the size of both matrices and their elements as input, calculates the resultant matrix, and displays it in matrix format. In sample input first line size of first array followed by its element in next line. third line size of second array followed by its elements in next line.

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