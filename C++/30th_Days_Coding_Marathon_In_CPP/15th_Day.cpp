//1) Given an array of N integers, sort them in ascending order using quick sort (a divide and conquer approach). It picks an element as pivot and partitions the given array around the picked pivot element recursively. Write the two functions quickSort() and partition(), in which the quickSort() choose an pivot using partition() function and calls itself on the two parts of array before and after the pivot element.
#include<iostream>
using namespace std;

int partition (int array[], int low, int high) {
  int pivot = array[high];
    int i = low - 1; 
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) { 
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]); 
    return i + 1;
}

void quickSort(int array[], int low, int high) {
 if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    } 
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int array[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    quickSort(array, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}




// 2) Given a list of strings, sort them in lexicographical order i.e. dictionary order.

// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// void sortStrings(int n, string str[]) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (str[j] > str[j + 1]) {
//                 swap(str[j], str[j + 1]);
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         cout << str[i];
//         if (i < n - 1) cout << " "; 
//     }
// }

//  int main(){
//     int t;
//     cin>>t;
//     while(t--){
//     int n;
//     cin>>n;
//     string str[n];
//     for(int i = 0; i < n; i++){
//         cin>>str[i];
//     }
//       sortStrings(n,str);
//     }
// return 0;
// }