#include<iostream>
using namespace std;
int main(){
    for(int i = 0; i < 10; i++){
        if(i == 2){
         goto end;
        }
        cout<<i<<endl;
    }
    end: 
    cout<<"out"<<endl;
    return 0;
}