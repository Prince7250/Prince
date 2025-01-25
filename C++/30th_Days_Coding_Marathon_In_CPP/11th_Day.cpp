//1)  Write a recursive function sumOfDigits that accepts an integer as a parameter and returns the sum of its digits. For example, calling sumOfDigits(1729) should return 1 + 7 + 2 + 9, which is 19. If the number is negative, return the negation of the value. For example, calling sumOfDigits(-1729) should return -19.

// Constraints: Do not declare any global variables. Do not use any loops; you must use recursion. Also do not solve this problem using a string. You can declare as many primitive variables like ints as you like. You are allowed to define other "helper" functions if you like; they are subject to these same constraints.

// #include <iostream>
// using namespace std;
// int SumOfDigits(int num)
//  {
//    if(num < 0){
//     return -SumOfDigits(-num);
//    }
//   if(num < 10){
//      return num;
//   }
//    return SumOfDigits(num / 10) + (num % 10);
// }

// int main()
//  { 
//     int a;
//     cin>>a;
//     cout<<SumOfDigits(a);
    
//     return 0;
// }

// 2) Prime factors using recursion 
// Write a program that accepts an integer n (where n >=2) and print all the prime factors of n using recursion.

#include <iostream>
using namespace std;

void primeFactors(int n, int divisor = 2) {
    if (n <= 1) {
        return;
    }
    if (n % divisor == 0) {
        cout << divisor <<endl;
        primeFactors(n / divisor, divisor);
    } else {
        primeFactors(n, divisor + 1);
    }
}

int main() {
    int n;
    cin >> n;
    primeFactors(n);
    return 0;
}