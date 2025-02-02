//1) Aim: Evaluate the prefix expression using Stack
// Given a prefix expression, evaluate it using stack and print the final output.
// Complete the evalPrefix() function and return the final output.
// Input Format
// The first line of input contains an integer T denoting the number of test cases. The next T
// lines contain a prefix expression.
// An expression in prefix form will consist of all digits and following five operators: +, -, *, /, ^
// Output Format
// Print the final output of prefix expression evaluation in new line for each test case.

// #include <bits/stdc++.h>
// using namespace std;

// #define SIZE 100
// int Stack[SIZE], top = -1;

// int isFull() {
//     return top == SIZE - 1;
// }

// int isEmpty() {
//     return top == -1;
// }

// int push(int item) {
//     if (!isFull()) {
//         Stack[++top] = item;
//         return 1;
//     }
//     return 0;
// }

// int pop() {
//     if (!isEmpty()) {
//         return Stack[top--];
//     }
//     return -1;
// }

// int evalPrefix(char* exp) {
//     int length = strlen(exp);
    
//     for (int i = length - 1; i >= 0; i--) {
//         if (isdigit(exp[i])) {
//             push(exp[i] - '0');
//         } else {
//             int op1 = pop();
//             int op2 = pop();
            
//             switch (exp[i]) {
//                 case '+': push(op1 + op2); break;
//                 case '-': push(op1 - op2); break;
//                 case '*': push(op1 * op2); break;
//                 case '/': push(op1 / op2); break;
//                 case '^': push(pow(op1, op2)); break;
//             }
//         }
//     }
//     return pop();
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         char expr[100];
//         cin >> expr;
//         cout << evalPrefix(expr) << endl;
//     }
//     return 0;
// }


//2) Aim: Evaluate the prefix expression using Stack
// Given a prefix expression, evaluate it using stack and print the final output.
// Complete the evalPrefix() function and return the final output.
// Input Format
// The first line of input contains an integer T denoting the number of test cases. The next T
// lines contain a prefix expression.
// An expression in prefix form will consist of all digits and following five operators: +, -, *, /, ^
// Output Format
// Print the final output of prefix expression evaluation in new line for each test case.

#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 1000

char Stack[SIZE];
int top = -1;

int isFull() {
    return top == SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
    } else {
        Stack[++top] = c;
    }
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    } else {
        return Stack[top--];
    }
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int infixToPostfix(char exp[], char output[]) {
    int k = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isalnum(ch)) {
            output[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && Stack[top] != '(') {
                output[k++] = pop();
            }
            pop();
        } else {
            while (!isEmpty() && precedence(ch) <= precedence(Stack[top])) {
                output[k++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        output[k++] = pop();
    }

    output[k] = '\0';
    return k;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        char exp[SIZE], output[SIZE];
        cin.getline(exp, SIZE);
        infixToPostfix(exp, output);
        cout << output << endl;
    }

    return 0;
}
