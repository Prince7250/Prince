#include<iostream>
#include<fstream>
using namespace std;
int main(){
     ofstream file1;
     file1.open("D:\\Prince\\C++\\aaa1.txt");
     file1<<"this is new file cefwe fwe oweo woehf wohfhfwqfqwf qdqw ";
    //  cout<<"data written in the file";
     file1.close();

    ifstream file;
    string str;
    file.open("D:\\Prince\\C++\\aaa1.txt");
    // file>>str;
    while(getline(file,str)){
        cout<<str;
    }
    
    file.close();
    return 0;
}
