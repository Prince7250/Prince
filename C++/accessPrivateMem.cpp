#include <iostream>
using namespace std;
class stud
{
private:
    void privateMem()
    {
        cout << "This is Private Member function ";
    }

    public : 
    void callPrivateMem(){
        privateMem();
    }
    // friend void privateMem(stud &st); // Private function access outside the class 

};
// void privateMem(stud &st)
// {
//     st.privateMem();
// }

int main()
{
    // stud s12;
    // privateMem(s12);
     stud s1;
     s1.callPrivateMem();
    return 0;
}