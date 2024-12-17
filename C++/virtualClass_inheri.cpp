

#include <iostream>
using namespace std;

class B
{
public:
    void show()
    {
        cout << "This is class 1." << endl;
    }
};
class C
{
public:
    void show()
    {
        cout << "This is class 2." << endl;
    }
};

class Derived : virtual public B, virtual public C
{
public:
    void show1()
    {
        cout << "This is class 3." << endl;
       
    }
};

int main()
{
    Derived d1;
    d1.B::show();
    // d1.d();
    // d1.c();
    // d1.b();
    // d1.a();
    return 0;
}