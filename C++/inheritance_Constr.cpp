#include<iostream>
using namespace std;
class number{
    int sum;
    public :
     number(int x,int y){
        sum = x + y;  
        cout<<"sum of "<<x<<" and "<<y<<" is = "<<sum;  
     }
};
// This program showcases various C++ concepts including class definition, object creation, constructor implementation, single inheritance, and basic mathematical operations like addition, multiplication, and checking for even/odd numbers.
class number1 {
    public:
    void table(){
        int n;
        cout<<"\n\nEnter any number to display of that table : ";
        cin>>n;
        for(int i = 1; i<=10; i++){
        cout<<n<<" x "<<i<<" = "<<n*i<<"\n";
        }
    }
};
class number2 : public number1 {
    public :
     void sum_of(){
       int n,sum=0;
       cout<<"\n\nEnter any number to find the sum of nth number : ";
       cin>>n;
       for(int i = 1; i <= n; i++){
        sum+=i; 
       }
        cout<<sum;
    }
};
class number3 : public number2 {
    public :
    void even(){
      int num;
      cout<<"\n\nEnter any number to find even and odd : ";
      cin>>num;
      if(num % 2 == 0)
      cout<<num<<" is even number.";
      else
      cout<<num<<" is odd number.";
    }
};

int main(){
     number num1 = number(23,45);
     number1 n1;
     n1.table();
    number3 num2;
    num2.even();
    num2.sum_of();
     return 0;
}
