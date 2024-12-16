#include <iostream>
using namespace std;
class stud1;
class stud
{
private:
    // string name = "Prince";
    int roll = 12;
    // int mob;
    friend void stud_details(stud, stud1);
};

class stud1
{
    int mob = 87169;
    friend void stud_details(stud, stud1);
};

void stud_details(stud s1, stud1 s2)
{
    cout << "Roll no. : " << s1.roll;
    cout<<"\nMob : "<<s2.mob;
}

int main()
{
    stud s1; 
    stud1 s2;
    
    stud_details(s1,s2);

    return 0;
}