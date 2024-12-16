#include <iostream>
using namespace std;

class A{
    public :
  static int a;
    void display(){
        cout<<"A : "<<a<<endl;
    }

};
 int A::a = 42;

int main(){
   cout<<A::a<<endl;  
A a1;
  a1.display();
    return 0;
}   
