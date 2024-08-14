#include <iostream>
using namespace std;
class A
{

public:
    void ice(int a, int b)
    {
        cout<<a+b;
    }
    void ice(int a, int b, int c){
        cout<<a+b+c;
    }
};
int main(){
    A pine;
    pine.ice(3,4,5);
    return 0;
}