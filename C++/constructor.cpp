#include<iostream>
using namespace std;

class num{
   int a,b,sum;
   public:
     num(int x,int y){
        sum = x+y; 
     }

     void display(){
        cout<<" Sum of two number : "<<sum;
     }

};
 int main(){
    num n1 = num(3,4);
    num n2 = num(98,34);
    n2.display();
    return 0;

 }T