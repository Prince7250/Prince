#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;


void capitalizeWords(char source[20], char dest[20])
{
  string = source;
  bool x = true;
   for(char &c = source){
    c = x ? toupper(c) : tolower(c);
    x = !isalpha(c);
   }
 for(int i = 0; i < source.length(); i++){
    bast[i] = source[i];
 }
   strcpy(dest , source.)
}

int main(){
    string str;
    bool val = true;
    cout<<"Enter string : "<<endl;
    getline(cin,str);
    // cout<<str;
    cout<<endl;
    
    // for(int i = 0; i < str.length(); i++){
    // str[i] = toupper(str[i]);
    // }

    // for(char &c : str){
    //     c = toupper(c);
    // }
    
    for (char &c : str) {
        
        c = val ? toupper(c) : tolower(c);
        val = !isalpha(c);
    }
    cout<<str;

  
    return 0;
}