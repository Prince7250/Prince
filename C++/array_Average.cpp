#include <iostream>
using namespace std;
int main()
{
    int arr[100], n, i, sum = 0;
    float ave;
    cout << "Enter count of number : ";
    cin >> n;
    cout << "Enter " << n << " times of any integer : ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array is : ";
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
        cout << " " << arr[i];
    }
    cout << "\nAddition of given array is : " << sum;
    ave = (float)sum / n;
    cout << "\nAverage of given number is : " << ave;
    return 0;
}
