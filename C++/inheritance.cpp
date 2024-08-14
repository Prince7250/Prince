#include<iostream>
using namespace std;
class colour
{
  public :
  void col(){
    cout<<"Black";
  }
   void col1(){
    cout<<"red";
  }
};
class colour1 : public colour 
{
    public:
    void col2(){
        cout<<"white";
    }
} ;
int main(){
    colour1 c1;
     c1.col();
     c1.col2();
    return 0;
}


