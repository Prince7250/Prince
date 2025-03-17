#include <iostream>
using namespace std;

int main()
{
    int a[3][3], b[3][3];
    int i, j;

    cout << "Enter element of the first matrix \n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cin>>a[i][j];
    }
    cout << "Enter element of the second matrix \n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cin>>b[i][j];
    }

    
    cout << "\n Display ADDTION of matrix\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cout <<a[i][j] + b[i][j];
        cout << "\n";
        return 0;
    }
}