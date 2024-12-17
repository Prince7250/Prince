#include<iostream>
using namespace std;
class exce{
  public :
  void test(){
    int age;
    cout<<"Enter age : ";
    cin>>age;
  try{
     if (age >= 18){
        cout<<"Eligleble for vote";
     }
     else {
     throw(age);
     }
  }
  catch(int num){
    cout<<"\nYour are not eligleble for vote : ";
  }
  }
};
int main(){
 exce e1;
  e1.test();
    return 0;
}