#include <iostream>
using namespace std;
const int MaxSize = 100;
int size, arr[MaxSize], top = -1, value = 0, ch;;

void push()
{
    if (top == size - 1)
    {
        cout << "Stack is overflow." << endl;
    }
    else
    {
        top++;
        arr[top] = value;
        cout << "Insert data is : " << value << endl;
    }
    cout << endl;
}

void pop()
{
    if (top == -1)
    {
        cout << "data is under flow." << endl;
    }
    else
    {
        value = arr[top];
        top--;
        cout << "Poped data is : " << value << endl;
    }
    cout << endl;
}

void peek()
{
    if (top == -1)
        cout << "\nStack is empty." << endl;
    else
        cout << "Peek value is : " << arr[top] << endl
             << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is Empty." << endl;
    }
    else
        cout << "\nData is : " << endl;
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    
    cout << "Enter the size of the stack : ";
    cin >> size;
    while(size < 1 || size > MaxSize){
     cout << "Invalid Size. Please Enter Size Between 1 to " << MaxSize << endl;
     cout << "\nRenter size of the stack : ";
    cin >> size;
}

while (true)
{
    cout << "              ---------------------------------------";
    cout << "\n              |    Stack Operations                 |" << endl;
    cout << "              |-------------------------------------|";
    cout << "\n              |   Which operation do you want :     |" << endl;
    cout << "              |         1. push                     |" << endl;
    cout << "              |         2. pop                      |" << endl;
    cout << "              |         3. peek                     |" << endl;
    cout << "              |         4. Display                  |" << endl;
    cout << "              |         5. Exit                     |" << endl;
    cout << "              ---------------------------------------";
    cout << "\n\nEnter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "\nEnter data to push: ";
        cin >> value;
        push();
        break;

    case 2:
        pop();
        break;

    case 3:
        peek();

        break;

    case 4:
        display();
        break;

    case 5:
        exit(0);
        break;

    default:
        cout << "Please Enter correct choice." << endl;
        break;
    }
}
return 0;
}