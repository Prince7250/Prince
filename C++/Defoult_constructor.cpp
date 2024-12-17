#include<iostream>
using namespace std;
 class area{
    int l , b;
    public:
    area(){
      l = 6;
      b = 23;
    }
    void display(){
      cout<<"Area of rectangle is : "<<l*b;
    }

 };

int main()
{
   area a1;
   a1.display();

return 0;
}