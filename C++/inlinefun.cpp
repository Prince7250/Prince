#include <iostream>
using namespace std;
inline int add(int a, int b)
{
    return a+b;
    
}

int main()
{
    int val = add(2,5);
    cout << "Addition of two number is : " << val;

    return 0;
}