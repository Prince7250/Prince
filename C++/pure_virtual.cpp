#include <iostream>
using namespace std;
class base
{
public:
    void show()
    {
        cout << "This is base class.";
    }
    virtual void display() = 0; // pure virtual class
};

class derived : public base
{
public:
    void display()
    {
        cout << "This is derived class.";
    }
};

int main()
{
    derived d1;
    //   d1.display();
    base *b1 = new derived();
    b1->display();
    

        return 0;
}