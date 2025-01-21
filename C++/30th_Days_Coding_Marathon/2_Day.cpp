// 1) Swap two value without using third variable.
// #include<iostream>
// using namespace std;

// int main()
// {
//   int a,b;
//     cin>>a>>b;
//     a = a + b;
//     b = a - b;
//     a = a - b;
//     cout<<a<<"\n"<<b;
//     return 0;
// }

//2) Add three numbers digit by digit.
#include<iostream>
using namespace std;
int addDigitByDigit(int a,int b,int c){
    return a+b+c;
}
int main()
{
    cout<<addDigitByDigit(12,23,23);
    
    return 0;
}
