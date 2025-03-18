#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

class StackItem {
public:
    virtual ~StackItem() {}
    virtual void print() const = 0;
    virtual StackItem* clone() const = 0;
};

template <typename T>
class TypedItem : public StackItem {
    T value;
public:
    TypedItem(T val) : value(val) {}
    void print() const override { cout << value; }
    StackItem* clone() const override { return new TypedItem<T>(value); }
};

template <>
class TypedItem<char> : public StackItem {
    char value;
public:
    TypedItem(char val) : value(val) {}
    void print() const override { cout << "'" << value << "'"; }
    StackItem* clone() const override { return new TypedItem<char>(value); }
};

class DynamicStack {
private:
    StackItem** stack;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        StackItem** newStack = new StackItem*[capacity];
        for (int i = 0; i < size; i++) {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
    }

public:
    DynamicStack() {
        capacity = 2;
        stack = new StackItem*[capacity];
        size = 0;
    }

    ~DynamicStack() {
        for (int i = 0; i < size; i++) {
            delete stack[i];
        }
        delete[] stack;
    }

    void push(const string& input) {
        if (size == capacity) {
            resize();
        }

        stringstream ss(input);
        int intValue;
        if (ss >> intValue && ss.eof()) {
            stack[size] = new TypedItem<int>(intValue);
            size++;
            return;
        }

        ss.clear();
        ss.str(input);
        float floatValue;
        if (ss >> floatValue && ss.eof()) {
            stack[size] = new TypedItem<float>(floatValue);
            size++;
            return;
        }

        if (input.length() == 1) {
            stack[size] = new TypedItem<char>(input[0]);
            size++;
            return;
        }

        if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
            stack[size] = new TypedItem<char>(input[1]);
            size++;
            return;
        }

        stack[size] = new TypedItem<char>(input[0]);
        size++;
    }

    StackItem* pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        size--;
        StackItem* item = stack[size];
        stack[size] = nullptr;
        return item;
    }

    StackItem* peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return stack[size - 1];
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack contents (top to bottom): ";
        for (int i = size - 1; i >= 0; i--) {
            stack[i]->print();
            if (i > 0) cout << " -> ";
        }
        cout << "\n";
    }
};

int main() {
    DynamicStack stack;
    int choice;

    while (true) {
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                string input;
                cout << "Enter value to push (e.g., 42, 3.14, A, 'b'): ";
                cin.ignore(10000, '\n');
                getline(cin, input);
                if (input.empty()) {
                    cout << "No input provided.\n";
                } else {
                    stack.push(input);
                    cout << "Pushed: " << input << "\n";
                }
                break;
            }

            case 2: {
                try {
                    StackItem* item = stack.pop();
                    cout << "Popped: ";
                    item->print();
                    cout << "\n";
                    delete item;
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            }

            case 3: {
                try {
                    StackItem* item = stack.peek();
                    cout << "Top element: ";
                    item->print();
                    cout << "\n";
                } catch (const runtime_error& e) {
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