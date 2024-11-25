#include <iostream>
using namespace std;
class A
{
public:
    void car()
    {
        cout << "this is car.";
    }
};
class B
{
public:
    void ca1()
    {
        cout << "this is car1.";
    }
};
class c : public A, public B
{
public:
    void car2()
    {
        cout << "This is car2.";
    }
};

int main()
{
 c c1;
 c1.car2();
    return 0;
}