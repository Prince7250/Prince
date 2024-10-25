#include<iostream>
using namespace std;

class count{
    public :
     static int total;
  count(){
    total+=1;
  }
};

int count :: total;

int main(){
      count s1;
      cout<<s1.total<<endl ;
      count s2;
      cout<<s2.total<<endl;
      count s3;
      cout<<s3.total;
    return 0;
}