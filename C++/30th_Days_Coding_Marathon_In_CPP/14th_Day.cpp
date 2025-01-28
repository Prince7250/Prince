// 1) Given a string, you need to test if it is palindrome or not. If the string is palindrome print “YES”, otherwise print “NO.

// #include<iostream>
// #include<string>
// using namespace std;

//  bool isPalindrome(string str) {
//   string rev = string(str.rbegin(), str.rend());
//      if (str == rev) {
//         return true;
//     } else {
//         return false;
//     }
// }
// int main()
// { int n;
// cin>>n;
// while(n--){
//     string str;
//     cin>>str;
//     if(isPalindrome(str)){
//         cout<<"Yes";
//     } else {
//         cout<<"No";
//     }
// }

// return 0;
// }

// 2) Reverse the words of a string bookmark_border
// A string is composing some words. These words are separated by some delimiter e.g. a space.

// Given a string (with space as a delimiter between words), reverse the words in the string individually, not the whole string.

// Complete the function revWordsString() which takes the string as parameter and reverse the individual words of string and print them.

#include <iostream>
#include <sstream>
#include<algorithm>
using namespace std;

// void revWordsString(string str) {
//     stringstream ss(str);
//     string word;
//     string rev = "";

//     while (ss >> word) {
//         reverse(word.begin(), word.end());
//         rev += word + " ";
//     }

//     rev.pop_back();
//     cout << rev<<endl;
// }

void revWordsString(string str) {
    stringstream ss(str);
    string word;
    bool first = true;
    while (ss >> word) {
        if (!first) {
            cout << " ";
        }
        reverse(word.begin(), word.end());
        cout << word;
        first = false;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter no of test case : ";
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string str;
        getline(cin, str);
        revWordsString(str);
    }
    return 0;
}