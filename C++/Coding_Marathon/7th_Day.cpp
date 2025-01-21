// //1)  Given a date with three elements date, month & year, your task is to print the next date of it.
// //  Online C++ compiler to run C++ program online
// #include <iostream>
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
    int date, month, year;
    cin >> date >> month >> year;
      int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
         if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
       month_days[1] = 29;
   } 
      if(month > 12 || month < 1 || date < 1 || date > month_days[month-1]){
      cout << "DDMMYYYY Is Not Valid";
        continue;;
    }
    date++;
    if (date > month_days[month - 1]){
        date = 1;
        month++;
        if (month > 12){
            month = 1;
            year++;
        }
    }
    cout << setfill('0')<<setw(2)<< date << "-" <<setw(2)<< month << "-" << year<<endl;
    }
    return 0;
}




//2)  Allocate a 1-D array of size nnn dynamically using malloc. The size n and its n elements are provided as input by the user. The program calculates the sum of the n elements and finds the average of these numbers. Finally, the dynamically allocated memory is freed to avoid memory leaks.
// In sample input first number is the size of array followed by these n numbers.
// sample input:
// 4 2 4 -2 1
// sample output:
// 2.50

// #include <iostream> 
// #include <cstdlib>
// using namespace std;
// int* dynamicMemoryAllocateArray(int n) {

//     int* arr = (int*)malloc(n * sizeof(int));
//     if (arr == nullptr) {
//         cout << "Memory allocation failed!" << endl;
//         exit(1); 
//     }
//     return arr; 
// }
// float findAverage(int *arr, int n) {
//     int sum = 0;

//     for (int i = 0; i < n; i++) {
//         sum += arr[i];
//     }
//     return static_cast<float>(sum) / n;
// }
