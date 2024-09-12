#include<iostream>
#include<limits>
using namespace std;
int main(){
  int a;
  while(true)
  {
    cout<<"\n\nEnter any number "<<endl;
    cin>>a;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter only Integer value .";
      continue;
    }
    break;
  }

    if(a%2==0)
      cout<<a<<" is a even number."<<endl;
      else
      cout<<a<<" is a odd number.";
    return 0;

}
