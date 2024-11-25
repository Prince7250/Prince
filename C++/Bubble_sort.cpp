#include <iostream>
using namespace std;
int main()
{
    int i, j, n, t, a[30];
    cout << "Enter the length of array";
    cin >> n;
    cout << "Enter array" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> "\t" << i;
        for (i = 0; i < n - 1; i++)
        {
            cout << "\n Number of pass:" << n - 1;
            for (j = 0; j < n - 1 - i; j++)
            {
                if (a[i] > a[j + 1])
                {
                    t = a[j];
                    a[j] = a[j + 1];
                    a = [j + 1] = t;
                }
            }
        }
    }
    cout << "Sorted array is:";
    for (i = 0; i < n; i++)
        cin >> i;
    return 0;
}
