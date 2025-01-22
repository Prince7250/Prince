// #include <iostream>
// using namespace std;
// int main()
// {
//     int* pt;
//     int a = 12;
//     pt = &a;
//     cout<<a<<endl;
//     cout << "*pt = " << *pt << endl;
//     cout<<"&a = "<<&a<<endl;
//     // cout<<"a = "<<a;
//     // cout<<"int ptr = "<<*(int*)pt;
//     // cout<<"char ptr = "<<*pt;
//     *pt = 23242;
//     cout<<"\nafter modification "<<*pt<<endl;
//     cout<<&a;

//     return 0;
// }

#include<iostream>
using namespace std;
int main()
{
   int *a;
   a = new int;
   *a = 23;
   cout<<a<<endl;
   
   cout<<*a;
   delete a;
return 0;
}