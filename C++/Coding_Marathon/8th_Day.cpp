//1) In C you can pass parameters to a function either by value or by reference. Changes made to variables passed by reference persists after the function. Hence you can pass any number of parameters as reference, which you want to return from function.

// Complete the function given below which takes several parameters and store the minimum, maximum & sum of array in passed pointer variables, so that it can be used in main function.

// void multiReturnArray(int *a, int size, int *min, int *max, int *sum)
// {
//      *min = a[0];
//     *max = a[0];
//     sum = 0;
//      for(int i = 0; i < size; i++){
//          if(*min > *a[i]){
//              *min = *a[i];
//          }
//          if(*max < *a[i]){
//              *max = *a[i];
//          }
//          *sum += *a[i]
//      }
 
// }

#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min = arr[0], max = arr[0], sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
        sum += arr[i];
    }
    cout<<min<<" "<<max<<" "<<sum<<endl;    
    return 0;
}