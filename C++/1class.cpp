// #include <iostream>
// using namespace std;
// class stud
// {
//     int Roll;
//     char name[10];
//     int mob_no;

// public :
//     void student()
//     {
//         cout << " Enter name of student ";
//         cin >>name;
//         cout << "Enter roll number ";
//         cin >> Roll;
//         cout<<"Enter Mobile number : ";
//         cin>>mob_no;
//     }
//     void display()
//     {
//         cout << " Roll number is : " << Roll;
//         cout<<"\n Name "<<name;
//     }
// }; 

// int main()
// {
//     stud s1;
//     s1.student();
//     s1.display();
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

vector<int> getRemovableIndices(string str1, string str2) {
    vector<int> indices;
    int index = -1;

    for (char c : str2) {
        index = str1.find(c, index + 1);
        if (index == string::npos) return {};
        indices.push_back(index);
    }

    return indices;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    vector<int> result = getRemovableIndices(str1, str2);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << "\n";

    return 0;
}
