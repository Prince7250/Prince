//1)  Given a number n, devise an algorithm to compute its square root.

// #include<iostream>
// #include<cmath>
// #include<iomanip>
// using namespace std;
// void squre(int n)
// {
//     int value;
//     float result;
//      for(int i = 0; i < n; i++){
//        cin>>value;
//        result = sqrt(value);
//        cout<<fixed<<setprecision(2)<<result<<endl;
//      }

// }

// int main()
// {
//      int n;
//      cin>>n;
//      squre(n);
// return 0;
// }



// 2) Given an array of n integers which is sorted but rotated by some number of times after sorting, and a integer k. Search the element k in this sorted rotated array efficiently. For example, suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Assume there are no duplicate elements in the array.
// Expected Time Complexity: O(log(N))
// Expected Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int searchRotatedSortedArray(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) return mid;

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (arr[mid] < k && k <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k;
        int n;
        cin >> k >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int result = searchRotatedSortedArray(arr, n, k);
        cout << result << endl;
    }

    return 0;
}
