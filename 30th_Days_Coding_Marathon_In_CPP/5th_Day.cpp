//1) Write a program to generate and print all the primes in the first n positive integers. 
// #include<iostream>
// using namespace std;
// int main()
//  {
//    int i, j, num, sum=0;
//    bool prime;
//    cin>>num;
//    for(i = 1; i <= num; i++){
//        prime = true;
//        for(j=2; j <= i/2;j++){
//           if(i % j == 0) {
//             prime = false;
//             break;
//           }
//        }
//           if(prime){
//             cout<<i<<endl;
//         }
//      }
//    return 0;
//   }


//2) Complete the below functions which will receive 3 integer pointers and print the sum of them.
// Note: Complete the given functions only, rest of the code is already written by the compiler for you.
#include<iostream>
using namespace std;
void sum(int *p1, int *p2, int *p3)
{
   cout<<*p1 +  *p2 + *p3;
         
}
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    sum(&a, &b, &c);
    return 0;
}