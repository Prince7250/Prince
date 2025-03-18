#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
using namespace std;

class StackItem
{
public:
    virtual ~StackItem() {}
    virtual void print() const = 0;
    virtual unique_ptr<StackItem> clone() const = 0;
};

template <typename T>
class TypedItem : public StackItem
{
    T value;

public:
    TypedItem(T val) : value(val) {}
    void print() const override { cout << value; }
    unique_ptr<StackItem> clone() const override { return make_unique<TypedItem<T>>(value); }
};

template <>
class TypedItem<char> : public StackItem
{
    char value;

public:
    TypedItem(char val) : value(val) {}
    void print() const override { cout << "'" << value << "'"; }
    unique_ptr<StackItem> clone() const override { return make_unique<TypedItem<char>>(value); }
};

class DynamicStack
{
private:
    vector<unique_ptr<StackItem>> stack;

public:
    void push(const string &input)
    {
        stringstream ss(input);
        int intValue;
        if (ss >> intValue && ss.eof())
        {
            stack.push_back(make_unique<TypedItem<int>>(intValue));
            return;
        }

        ss.clear();
        ss.str(input);
        float floatValue;
        if (ss >> floatValue && ss.eof())
        {
            stack.push_back(make_unique<TypedItem<float>>(floatValue));
            return;
        }

        if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        {
            stack.push_back(make_unique<TypedItem<char>>(input[1]));
            return;
        }

        stack.push_back(make_unique<TypedItem<char>>(input[0]));
    }

    unique_ptr<StackItem> pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        auto item = move(stack.back());
        stack.pop_back();
        return item;
    }

    StackItem *peek() const
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        return stack.back().get();
    }

    bool isEmpty() const
    {
        return stack.empty();
    }

    int getSize() const
    {
        return stack.size();
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack contents (top to bottom): ";
        for (int i = stack.size() - 1; i >= 0; i--)
        {
            stack[i]->print();
            if (i > 0)
                cout << " -> ";
        }
        cout << "\n";
    }
};

int main()
{
    DynamicStack stack;
    int choice;

    while (true)
    {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if empty\n";
        cout << "5. Get size\n";
        cout << "6. Display stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            string input;
            cout << "Enter value to push (e.g., 42, 3.14, A, 'b'): ";
            cin.ignore();
            getline(cin, input);
            if (input.empty())
            {
                cout << "No input provided.\n";
            }
            else
            {
                stack.push(input);
                cout << "Pushed: " << input << "\n";
            }
            break;
        }

        case 2:
        {
            try
            {
                auto item = stack.pop();
                cout << "Popped: ";
                item->print();
                cout << "\n";
            }
            catch (const runtime_error &e)
            {
                cout << "Error: " << e.what() << "\n";
            }
            break;
        }

        case 3:
        {
            try
            {
                StackItem *item = stack.peek();
                cout << "Top element: ";
                item->print();
                cout << "\n";
            }
            catch (const runtime_error &e)
            {
                cout << "Error: " << e.what() << "\n";
            }
            break;
        }

        case 4:
            cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << "\n";
            break;

        case 5:
            cout << "Stack size: " << stack.getSize() << "\n";
            break;

        case 6:
            stack.display();
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    }

    return 0;
}
