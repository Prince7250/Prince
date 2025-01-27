// Write a function mergeArrays which should merge two sorted arrays A and B to create one single sorted array.

// If the number of elements initialized in A and B are m and n respectively, the resulting size of merged array after your code is executed should be m + n

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int* mergeArrays(int a[], int b[], int asize, int bsize) {

//     int* merged = new int[asize + bsize];
    
//     for (int i = 0; i < asize; i++) {
//         merged[i] = a[i];
//     }
    
//     for (int i = 0; i < bsize; i++) {
//         merged[asize + i] = b[i];
//     }
    
//     sort(merged, merged + asize + bsize);
//     return merged;
// }

// // int merge_array(int a[], int b[], int asize, int bsize)
// // {
// //     int mer[asize + bsize];

// //     for (int i = 0; i < asize; i++)
// //     {
// //         mer[i] = a[i];
// //     }
// //     for (int i = 0; i < bsize; i++)
// //     {
// //         mer[asize  + i] = b[i];
// //     }

// //     return mer;
// // }

// // int* mergeArrays(int a[], int b[], int asize, int bsize) {
// //  int* merged = new int[asize + bsize];
// //     int i = 0, j = 0, k = 0;

// //     while (i < asize && j < bsize) {
// //         if (a[i] < b[j]) {
// //             merged[k++] = a[i++];
// //         } else {
// //             merged[k++] = b[j++];
// //         }
// //     }

// //     while (i < asize) {
// //         merged[k++] = a[i++];
// //     }

// //     while (j < bsize) {
// //         merged[k++] = b[j++];
// //     }

// //     return merged;
// // }

// int main()
// {
//     int asize;
//     cout << "Enter First array size : ";
//     cin >> asize;
//     int a[asize];
//     for (int i = 0; i < asize; i++)
//     {
//         cin >> a[i];
//     }

//     int bsize;
//     cout << "\nEnter Second array size : ";
//     cin >> bsize;
//     int b[bsize];
//     for (int i = 0; i < bsize; i++)
//     {
//         cin >> b[i];
//     }

//     cout<<"\nArray after merging : ";
//     int* mearged = mergeArrays(a, b, asize, bsize);
//     for (int i = 0; i < asize + bsize; i++)
//     {
//         cout << mearged[i] << " ";
//     }

//     return 0;
// }


// Given a method called kthLargest that accepts an integer k and an array arr as its parameters and returns the element such that k elements have greater or equal value. If k = 0, return the largest element; if k = 1, return the second largest element, and so on.

// For example, if the array passed contains the values {74, 85, 102, 99, 101, 56, 84} and the integer k passed is 2, your method should return 99 because there are two values at least as large as 99 (101 and 102).

#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = rand() % (high - low + 1) + low;
        swap(arr[pivotIndex], arr[high]);
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex == k) {
            return arr[partitionIndex];
        } else if (partitionIndex < k) {
            return quickselect(arr, partitionIndex + 1, high, k);
        } else {
            return quickselect(arr, low, partitionIndex - 1, k);
        }
    }
    return -1;
}

int kthLargest(int arr[], int size, int k) {
    return quickselect(arr, 0, size - 1, k);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k, N;
        cin >> k >> N;
        
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        cout << kthLargest(arr, N, k) << endl;
    }

    return 0;
}
