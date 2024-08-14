#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "\n\nEnter any number to display of that table : ";
    cin >> n;
    for (int i = 1; i <= 10; i++)
    {
        cout << n << " x " << i << " = " << n * i << "\n";
    }
    return 0;
}
