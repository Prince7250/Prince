//1) Given a sorted list of N integers, find all distinct pairs of integers in the list with sum equal to a given number K, with O(n log n) or O(n) time complexity.
// Complete the function below which takes the array and K as parameters and return the number of pairs if any and 0 otherwise.
// Online C++ compiler to run C++ program online

// #include <iostream> 
// #include <unordered_map>
// using namespace std;
// int getPairsCount(int arr[], int n, int k) {
//     unordered_map<int, int> freq;
//     int count = 0;

//     for (int i = 0; i < n; i++) {
//         int complement = k - arr[i];
//         if (freq.find(complement) != freq.end()) {
//             count += freq[complement];
//         }
//         freq[arr[i]]++;
//     }

//     return count;
// }

// int main() {
//     int x;
//     cin>>x;
//     for(int i = 0; i < x; i++){
//         int n,k;
//         cin>>n>>k;
//         int arr[n];
//         for(int i = 0; i < n; i++){
//             cin>>arr[i];
//         }
//         cout<<getPairsCount(arr,n,k)<<endl;
//     }
//     return 0;
// }


// 2) Given a sorted list of integers with duplicates, find the count of a given number K in that list in O(log n) time
#include <iostream>
#include<unordered_map>
using namespace std;
// int dublicate_numbers(int arr[], int n, int k)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == k)
//         {
//             count++;
//         }
//     }
//     return count;
// }

int dublicate_numbers(int arr[],int n, int k){
    unordered_map<int, int> count;
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    return count[k];    

}
int main()
{
    int x;
    cin>>x;
    for(int i = 0; i < x; i++){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<dublicate_numbers(arr, n, k)<<endl;
    }
    return 0;
}
