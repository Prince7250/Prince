// 1) Calculate Discount based on type of customer bookmark_border
//   Write a program to input gross amount of bill and calculate the net amount according to the below discounts:
//   If amount < 1000, then discount is 0%
//   If amount is from 1001 to 5000, then discount is 5%
//   If amount is from 5001 to 10000, then discount is 10%
//   If amount > 10000, then discount is 15%
//   An additional discount of 2% if bill is greater than 30000.
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float amount,discount,netamount;
    cout<<"Enter Amount : "<<endl;a
    cin>>amount;
    if(amount <= 1000){
       discount = 0;
    }
    else if(amount >= 1001 && amount <=5000){
        discount = 5;
    }
    else if(amount >= 5001 && amount <= 10000){
        discount =  10;
    }
    else if(amount > 10000 && amount <= 30000){
        discount = 15;
    }
    else{
         discount = 15 + 2;
    }

    netamount = amount - (amount * discount / 100);
    cout<<"Your payment amount is Rs "<<fixed<<setprecision(2)<<netamount;
    return 0;
}


// 2) Create Simple calculator of four operations using switch case bookmark_border
//    Write a program to create menu driven calculator that performs basic arithmetic operations (add, subtract, multiply and divide) using switch case. The calculator should input two numbers and an operator from user. It should perform operation according to the operator entered and must take input in given format.
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float x , y;
    char op;
    cin>>x>>op>>y;
  
        switch(op){
            case '+' :
                  cout<<fixed<<setprecision(2)<<x+y;
                  break;
            case '-' :
                  cout<<fixed<<setprecision(2)<<x-y;
                  break;
            case '*' :
                  cout<<fixed<<setprecision(2)<<x*y;
                  break;
            case '/' :
                  cout<<fixed<<setprecision(2)<<x/y;
                  break;
              default :
                  cout<<"Invalid Input";
        }
   return 0;
}