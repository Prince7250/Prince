// Given a number n, devise an algorithm to compute its square root.

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void primeFactors(int n)
{
    int value;
    float result;
     for(int i = 0; i < n; i++){
       cin>>value;
       result = sqrt(value);
       cout<<fixed<<setprecision(2)<<result<<endl;
     }

}

int main()
{
     int n;
     cin>>n;
     primeFactors(n);
return 0;
}