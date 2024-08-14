#include<iostream>
using namespace std;
int main(){
    int a=0,data,i;
    cout<<"\n\nEnter any number : ";
    cin>>data;

    for(i=2; i < data; i++){
        if(data % i == 0){
        a++;
      break;
        
    }
    }

    if(a==1 )
    cout<<data<<" is a not Prime number ";

    else

    cout<<data<<" is a Prime number ";

    main();

    return 0;
}
