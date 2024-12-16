#include <iostream>
using namespace std;
int fun(int a)
{
    return a;
} 
int fun(int a, int b)
{
    return a + b;
}

int fun(int a, int b, int c)
{
    return a + b + c;
}

int main()
{ 
    cout<<"Number : "<<fun(12)<<endl;
    cout<<"Add : "<<fun(1,43)<<endl;
    cout<<"Addition : "<<fun(12,33,52);

    return 0;
}