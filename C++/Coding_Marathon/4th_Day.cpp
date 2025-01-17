//1) Write a program to input any number from user and check whether the given number is perfect number or not.
#include<iostream>
using namespace std;
int main()
{
    int i,num,sum=0;
    cin>>num;
    for(i = 1; i < num; i++){
        if(num % i == 0){
            sum += i;
        }
    }
   cout<<((sum == num) ? "yes" : "no");        
   return 0;
}