#include <iostream>
using namespace std;

class stud
{ 
    public:
    static int total;
        stud (){
            total+=1;
        }
};
int stud::total = 0;

int main(){
    stud s1;
    cout<<"Total : "<<s1.total<<endl;
    stud s2;
    cout<<"Total1 : "<<s2.total<<endl;
    stud s3;
    cout<<"Total2 : "<<s3.total<<endl;
    return 0;
}

