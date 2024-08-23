#include <iostream>
// #include <vector>
using namespace std;
int size, arr[100], top = -1;

void push()
{
    if (top == size - 1)
    {
        cout << "Stack is overflow.";
    }
    else
    {
        // top++;
        cout << "Insert data is : " << arr[top];
        top++;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "data is under flow.";
    }
    else
    {
        top--;
        cout << "Poed data is : " << arr[top];
    }
}

void peek()
{
    if (top == -1)
        cout << "Stack is empty.";
    else
        cout << "Top value is : " << arr[top];
}

void display()
{
    if (top == 0)
    {
        cout << "Stack is Empty.";
    }
    else
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
}

int main()
{
    int ch;
    // vector<int> vec;
    cout << "Enter the size of the stack : ";
    cin >> size;
    cout << "\n   This is the stack operation : " << endl;
    cout << "-------------------------------------";
x:
{
    cout << "\n\nWhich operation do you want : " << endl;
    cout << "   1. push " << endl;
    cout << "   2. pop " << endl;
    cout << "   3. peek " << endl;
    cout << "   4. Display" << endl;
    cout << "   5. Exit " << endl;
    cout << "Enter any operation : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "\nEnter data to push: ";
        cin >> arr[top];
        push();
        break;

    case 2:
        pop();
        break;

    case 3:
        peek();

        break;

    case 4:
        cout << "\nData is : ";
        display();
        break;

    case 5:
        exit(0);
        break;

    default:
        cout << "\nEnter another choice.";
        break;
    }
}
    goto x;

    return 0;
}