#include<iostream>
using namespace std;
//  class area{
//     int l , b;
//     public:
//     area(){
//       l = 6;
//       b = 23;
//     }
//     ~area(){
//       cout<<"\nDefoult destructor called ";
//     }
//     void display(){
//       cout<<"Area of rectangle is : "<<l*b;
//     }

//  };

class number{
  public:
  number(){
    num++;
    cout<<"\nDefault constructor called "<<endl;
  }

};
int main()
{
   area a1;
   a1.display();

return 0;
}