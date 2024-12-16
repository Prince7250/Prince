                    // Compile time function Overriding
#include <iostream>
using namespace std;
class emp
{
public:
    int emp_id = 131324;
    string name = "Santosh";
   void show()
    {
        cout << "emp_id : " << emp_id;
        cout << "\nname : " << name << endl;
    }
    void dis(){
        cout<<"\nThis is base class.";
    }
};
class emp1 : public emp
{
public:
    int a = 13;
    void show()
    {
        cout << "\nA : " << a << endl;
    }
    void dis(){
        cout<<"\nThis is derived class.";
    }
};

int main()
{
    
   emp1 e1;
   emp *ptr = &e1;
   ptr->show();
   ptr->dis();
   e1.dis();

    // emp1 e1;
    // e1.show();
    // e1.emp::dis();


    return 0;
}