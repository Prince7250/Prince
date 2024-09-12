#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main()
{
  int data;
  while (true)
  {
    int a = 0;
    cout << "\n\nEnter any number : ";
    cin >> data;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter only Integer value .";
      continue;
    }

    if (data <= 1)
    {
      cout << data << " is not prime number." << endl;
      continue;
    }

    

      for (int i = 2; i <= sqrt(data); i++)
      {
        if (data % i == 0)
        {
          a++;
          break;
        }
      }
      if (a == 1)
        cout << data << " is a not Prime number. ";
      else
        cout << data << " is a Prime number. ";
    
  }
  return 0;
}
