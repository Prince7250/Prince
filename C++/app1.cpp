// #include<iostream>
// using namespace std;
// int main(){
//     int a,b;
//     cout<<"Enter any two number :";
//     cin>>a;
//     cin>>b;
//     if (a>b)
//     cout<<a<<" is greater then "<<b;
//     else
//     cout<<b<<" is greater than "<<a;
//     // main();
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int input;

    cout << "Enter elements of the array (enter any non-integer to stop):" << std::endl;

    // Loop to take input until a non-integer is entered
    while (cin >> input) {
        arr.push_back(input);
    }

    cout << "You entered:" << std::endl;

    // Loop to display the elements
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
