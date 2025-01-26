//1) Write a recursive function gcd that accepts two positive non-zero integer parameters i and j and returns the greatest common divisor of these numbers. almost fing HCF

// #include <iostream>
// using namespace std;
// int gcd(int i, int j)
// {
//     if(i == 0){
//         return j;
//     }
//     return gcd(j % i, i);
// }

// int main()
// {
//     int a, b;
//     char ch;
    
//     return 0;
// }

// 2)  Given an array of integers and a positive integer R, rotate the array by shifting each element by R positions towards the left in a circular manner.
// First line will contain the number of test cases. Each test case will contain 3 lines. 
// First line of the test case will contain a number n = number of elements in the array. 
// next line will contain n space separated integers. 
// The third line will contain an integer R = number of shifts in rotation. It is possible that R is greater than n.
// Print one line of output for each test case with the integers in the rotated array printed as space separated list.

#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int r) {
    r = r % n;
    
    for (int i = r; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }

    for (int i = 0; i < r; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, r;
        cin >> n;

        int arr[1000];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cin >> r;
        rotateArray(arr, n, r);
    }

    return 0;
}

