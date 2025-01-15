#include <iostream>
#include <limits>
using namespace std;
const int MaxSize = 100;
int size, arr[MaxSize], top = -1, value = 0, ch;
void push()
{
    if (top == size - 1)
    {
        cout << "Stack is overflow." << endl;
    }
    else
    {
        int count;
        cout << "How many elements do you want to push? ";
        cin >> count;
        
        // Check if there's enough space in stack
        if (top + count >= size)
        {
            cout << "Cannot push " << count << " elements. Only " << (size - top - 1) << " spaces left." << endl;
            return;
        }

        cout << "Enter " << count << " elements:" << endl;
        for (int i = 0; i < count; i++)
        {
            cin >> value;
            arr[++top] = value;
        }

        cout << "\nInserted data is : " << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
// void push()
// {
//     if (top == size - 1)
//     {
//         cout << "Stack is overflow." << endl;
//     }
//     else
//     {
        
//         //  while(){
//         //     arr[top] = value;
//         //     top++;
//         //  }
//         // arr[top] = value;
//         // top++;
//         arr[++top] = value;

//         // for (int i = 0; i <= top; i++)
//         // {
//         //     arr[i] = value;
//         // }

//         cout << "\nInserted data is : " << endl;
//         for (int i = 0; i <= top; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         // cout << "\nInsert data is : " << value << endl;
//     }
//     cout << endl;
// }

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
    while (true)
    {

        cout << "Enter the size of the stack : ";
        cin >> size;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // cout << "Invailed choice, Please Enter only integer value." << endl;
        }

        else
            break;

        while (size < 1 || size > MaxSize)
        {
            cout << "Invalid Input, Please Enter only integer value Between 1 to " << MaxSize << endl;
            cout << "\nRenter size of the stack : ";
            cin >> size;
        }
    }

    while (true)
    {
        cout << "              ---------------------------------------";
        cout << "\n              |    Stack Operations                 |" << endl;
        cout << "              |-------------------------------------|" << endl;
        cout << "              |   Which operation do you want :     |" << endl;
        cout << "              |         1. push                     |" << endl;
        cout << "              |         2. pop                      |" << endl;
        cout << "              |         3. peek                     |" << endl;
        cout << "              |         4. Display                  |" << endl;
        cout << "              |         5. Exit                     |" << endl;
        cout << "              ---------------------------------------";
        while (true)
        {
            cout << "\n\nEnter your choice : ";
            cin >> ch;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Choice, Please Enter only integer value.";
            }
            else
                break;
        }

        switch (ch)
        {
        case 1:
            while (true)
            {
                cout << "\nEnter data to push: ";
                cin >> value;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Choice. Please Enter only integer value";
                }
                else
                {
                    break;
                }
            }

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
            cout << "Invalidd chose. Please Enter Between 1 to 5 " << endl
                 << endl;
            break;
        }
    }
    return 0;
}