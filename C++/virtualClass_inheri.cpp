#include <iostream>
using namespace std;

class A {
public:
A(){
    cout<<"This is constructor of class A."<<endl;
}
~A(){
    cout<<"This is Destructor of class A."<<endl;
}
     void a()
    {
        cout << "This is class a." << endl;
    }
};
class B : virtual public A {
public:
    void b()
    {
        cout << "This is class b." << endl;
    }
};
class C : virtual public A{
public:
    void c()
    {
        cout << "This is class c." << endl;
    }
};

class Derived : public B , public C{
    public :
    void d(){
        cout<<"This is class d."<<endl;
    }
};

int main(){
    Derived d1;
    d1.a();
    // d1.d();
    // d1.c();
    // d1.b();
    // d1.a();
    return 0;
}