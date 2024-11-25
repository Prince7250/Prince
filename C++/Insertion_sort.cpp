#include <iostream>
using namespace std;
int main()
{
    int i, j, temp, n, A[30];
    cout << "Enter the length of array:" << endl;
    cin >> n;
    cout << "Enter the array:" << endl;
    for (i = 0; i < n; i++)
        cin >> A[i];
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
    cout << "Sorted array is:" << endl;
    for (i = 0; i < n; i++)
        cout << " \t" << A[i];
    return 0;
}
