#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int element, sum = 0;
    vector<int> vec;

    cout << "Enter element how much you want(enter any char to process next operation) : ";

    while (cin >> element)
    {
        vec.push_back(element);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
        cout << vec[i] << " ";
    }
    cout << "\nsum of given data is sum : " << sum << endl;
    cout << "Average of given data is : " << (float)sum / vec.size();
    return 0;
}