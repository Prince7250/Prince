#include<iostream>
#include<cctype>
// #include<cstring>
// #include<cstring>
using namespace std;


void capitalizeWords(char source[200], char dest[200])
{
  string str = source;
  bool x = true;
   for(char &c : str){
    c = x ? toupper(c) : tolower(c);
    x = !isalpha(c);
   }
 for(int i = 0; i < str.length(); i++){
    dest[i] = str[i];
 }
 dest[str.length()] = '\0';
 cout<<"\n";
   cout<<dest;
}

int main()
{
     string str;
     char dest[200];
     cout<<"Enter any string : ";
     getline(cin,str);
     cout<<"\n"<<str;
     char ch[200];
     for(int i = 0; i < str.length(); i++){
        ch[i] = str[i];
     }
     capitalizeWords(ch , dest);
    
return 0;
}