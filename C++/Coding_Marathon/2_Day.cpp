// 1) Swap two value without using third variable.
#include <iostream>
using namespace std;
int main()
{
    int a = 10, b = 20;
    cout << a << "\n" << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << "\n" << b;
    return 0;
}