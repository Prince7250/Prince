#include <iostream>
using namespace std;

class A
{
private:
    int a = 10;

protected:
    int b = 13;

public:
    void show()
    {
        cout << a << " " << b<<endl;
    }
    friend class B;
};

class B
{
public:
    void Dis(A a3)
    {
        cout << "\n a = " << a3.a;
        cout << "\n b = " << a3.b;
    }
};

int main()
{
    A a1;
    a1.show();
    B b1;
    b1.Dis(a1);
    return 0;
}