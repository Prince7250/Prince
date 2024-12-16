#include<iostream>
#include<string>
using namespace std;
int main()
{
    string result , st1 , st2;
 cout<<"Enter name : ";
 getline(cin,st1);
 cout<<"\nEnter second sentance : ";
 getline(cin,st2);
 result = st1 + st2;
 cout<<"\nResult : "<<result;
return 0;
}