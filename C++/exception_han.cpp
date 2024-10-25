#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"Enter age : ";
    cin>>age;
    try{
        if(age >= 18){
            cout<<"your are eligilabe for vote "<<endl;
        }
        else 
        throw(age);
    }
   catch (int ag){
    cout<<"your are not eligibale for vote."<<endl;
    cout<<ag<<endl;
   }
   main();
    return 0;
}