#include<iostream>
using namespace std;
int isum(int x){
    if(x == 0){
        return 0;
    }
    return x + isum(x - 1);
}
int main()
{
  int a,sum=0;
  cout<<"\nEnter any number : ";
  cin>>a;
  cout<<isum(a);

return 0;
}