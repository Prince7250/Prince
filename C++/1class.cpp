#include <iostream>
using namespace std;
class stud
{
private:
    int Roll;
    char name[10];
    int mob_no;

public :
    void student()
    {
        cout << " Enter name of student ";
        cin >>name;
        cout << "Enter roll number ";
        cin >> Roll;
        cout<<"Enter Mobile number : ";
        cin>>mob_no;
    }
    void display()
    {
        cout << " Roll number is : " << Roll;
        cout<<"\n Name "<<name;
    }
};

int main()
{
    stud s1;
    s1.student();
    s1.display();
    return 0;
}
