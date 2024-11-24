#include <iostream>
using namespace std;
void printarray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << "\n";
}
void selectionsort(int A[], int n)
{
    int min, swap;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[min] > A[j])
                min = j;
        }
        if (min != i)
        {
            swap = A[i];
            A[i] = A[min];
            A[min] = swap;
        }
    }
}
int main()
{
    int A[] = {8, 9, 1, 2, 5, -4};
    int n = 6;
    cout << "Unsorted array :" << endl;
    printarray(A, n);
    cout << "Sorted array :" << endl;
    selectionsort(A, n);
    printarray(A, n);
    return 0;
}
