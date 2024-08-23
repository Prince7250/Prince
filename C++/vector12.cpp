#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    int i, element;
    cout << "Enter data : ";
    for (i = 0; i < 10; i++)
    {
        cin >> element;
        vec.push_back(element);
    }
  
    for (i = 0; i <vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}