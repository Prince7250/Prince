#include<iostream>
using namespace std;

// What is struct ?
// struct is keyword, it is use to group several related variable in once.

struct area {
    int l,b;
};

int main(){
struct area a1;
struct area a2;
a1.l = 12;
a1.b = 43;
cout<<" area of first rectangle : "<<a1.l*a1.b;

a2.l = 43;
a2.b = 5;
cout<<"\narea of secont rectrangle : "<<a2.l*a2.b;


return 0;
}