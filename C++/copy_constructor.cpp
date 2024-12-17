#include<iostream>
using namespace std;
class add{
    int a ,b;
    public :
    add(){ a = 2; b = 5;}
    add(int x,int y){
        a = x;
        b = y;
    }

    //  add(add &obj){
    //     a = obj.a;
    //     b = obj.b;
    //  }

    void dis(){
        cout<<a<<" "<<b<<endl;
    }
};
int main()
{
 add a1, a2(23,35);
 a1.dis();
 a2.dis();
 
 add a3(a2);
 a3.dis();

 add a4(a3);
 a4.dis();


return 0;
}