#include<iostream>
using namespace std;
class stud{
    string name = "Prince";
    int roll = 341243243;
    public :
   virtual void detail(){
    cout<<"Name : "<<name<<endl;
    }
};

class stud2 : public stud {
    string name = "Rohit";
    int roll = 23523543;
    public :
    void detail(){
        cout<<"Name : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
    }
};

int main()
{
    // stud s1;
    // s1.detail();
    // stud2 s2;
    // s2.deta();
    // s2.stud::detail();

    stud *s1;
    stud2 s2;
    s1 = &s2;
    s1->detail();
    
return 0;
}