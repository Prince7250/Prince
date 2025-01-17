//1) Write a program to input any number from user and check whether the given number is perfect number or not.
// #include<iostream>
// using namespace std;
// int main()
// {
//     int i,num,sum=0;
//     cin>>num;
//     for(i = 1; i < num; i++){
//         if(num % i == 0){
//             sum += i;
//         }
//     }
//    cout<<((sum == num) ? "yes" : "no");        
//    return 0;
// }


//2) Write a program to print the n lines of the below pyramid
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// Important Note: Don't print spaces at the end of the last row.

#include<iostream>
using namespace std;
int main()
{
    int i , j , n , num = 1;
    cin>>n;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            cout<<num;
            if (j < i) {
                cout << " ";
            }
            num++;
        }
        cout<<endl;
    }
    
   return 0;
}