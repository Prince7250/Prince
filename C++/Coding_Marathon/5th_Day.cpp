//1) Write a method threeConsecutive(int a,int b,int c) that accepts three integers as parameters and returns 1 if they are three consecutive numbers ( i.e if the numbers can be arranged into an order such that their values differ by exactly 1 ) otherwise return 0.

//For example, the call of ThreeConsecutive(3, 2, 4) would return 1.
// #include<iostream>
// using namespace std;

// int threeConsecutive(int a, int b, int c) {
//     int minnum , maxnum , midnum;
//     minnum = min(a, min(b, c));
//     maxnum = max(a, max(b, c));
//     midnum = a + b + c - minnum - maxnum;

//     if (maxnum - midnum == 1 && midnum - minnum == 1) {
//         return 1;
//     }
//     return 0;
// }

// int main(){
//     int a , b ,c;
//     cin>>a>>b>>c;
//    if(threeConsecutive(a, b, c)){
//     cout<<"1";
//    }
//    else {
//     cout<<"0";
//    }
//     return 0;
// }


//2) Write a function void reverseArray(int *a, int size) which takes two parameters i.e. an pointer to first element of array, an integer size.

// The function must reverse the array elements inside the array, Don't print the array elements as printing is done in main function.
 
 #include<iostream> 
 using namespace std;
    void reverseArray(int *a, int size) {
        int i, temp;
        for(i = 0; i < size / 2; i++) {
            temp = a[i];
            a[i] = a[size - 1 - i];
            a[size - 1 - i] = temp;
        }
    }

    int main(){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        reverseArray(a, n);
        for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        return 0;
    }