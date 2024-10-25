#include<iostream>
using namespace std;
class friend_fu{
    private:
    int a=12,b=27;
    
  public :
    void num(){
        cout<<"\nnumber is : "<<a<<" and "<<b<<endl;
    }

    friend int add(friend_fu f2);
};

  int add(friend_fu f2){

    return f2.a+f2.b;
  }

int main(){
   friend_fu f1,f3;
   f1.num();
   cout<<"Sum of two number is : "<<add(f3);

    return 0;
}