// //1) Write a program to show how to read and write integer values from user.
// #include<iostream>
// using namespace std;
// int main(){
//  int a,b,c;
//     cout<<"Enter three numbers : ";
//     cin>>a>>b>>c;
//     cout<<a<<" "<<b<<" "<<c;
//  return 0;
//  }

 //2) Input two numbers x and y from keyboard you need to print the sum of two numbers with 2 decimal digit.
#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
   float x,y;
   cin>>x>>y;
   cout<<fixed<<setprecision(2)<<x+y;
   return 0;
}
