#include <iostream>
// #include <vector>
using namespace std;

class MyClass {
// public:
//     void printNumbers() {
//         int n;
//         cout<<"enter number ";
//         cin>>n;
//         for (int i = 1; i <= n; i++) {
//             cout << i << " ";
//         }
//     }
     public :
     void printNumbers(){
       int n,sum=0;
       cout<<"\n\nEnter any number to find sum of 1 to that number : ";
       cin>>n;
       for(int i = 1; i <= n; i++){
         if(sum += i)
         cout<<sum;
       }
    }
};

int main() {
    MyClass obj;
    obj.printNumbers();

    return 0;
}