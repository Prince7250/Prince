#include <iostream>
using namespace std;

class sum
{
    int a, b;

public:
    sum(int x, int y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "Sum : " << a + b;
    }
};

int main()
{
 sum s1(12,43);
 s1.display();
 
 return 0;
}