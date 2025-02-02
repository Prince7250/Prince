//1) Implement circular queue using array bookmark_border
// Implement the circular queue using array representation.Complete the methods given in the editor.

// Input Format:

// First line of input contains number of test cases, T. The T test cases follow
// First line of each test case contains an integer Q denoting the number of queries.
// (a) 1 item  (a query of this type means insert 'item' into the queue)
// (b) 2   (a query of this type means to delete element from queue and print the deleted element)
// Then Q queries follow in following lines.

//2) Implement the queue using Linked List bookmark_border
// Implement the queue using linked list representation. Complete the methods given in the code editor.

// Input Format

// First line of input contains an integer Q denoting the number of queries.
// (a) 1 item  (a query of this type means insert 'item' into the queue)
// (b) 2   (a query of this type means to delete element from queue and print the deleted element)
// The second line of each test case contains Q queries separated by space.
// Output Format
// The output for each test case will be space separated integers having -1 if the queue is empty else the element deleted from the queue.

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Queue { 
    struct QNode { 
        int data; 
        QNode* next; 
        QNode(int d) { 
            data = d; 
            next = NULL; 
        } 
    }; 

    QNode *front, *rear; 

public:
    Queue() {
        front = rear = NULL;
    }

    void enQueue(int x) {
        QNode* newNode = new QNode(x);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int deQueue() {
        if (front == NULL) {
            return -1;
        }
        int data = front->data;
        QNode* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return data;
    }
};

int main() {
    int Q;
    cin >> Q;
    Queue q;
    
    vector<int> result;

    for (int i = 0; i < Q; i++) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int item;
            cin >> item;
            q.enQueue(item);
        } else if (queryType == 2) {
            int deletedItem = q.deQueue();
            result.push_back(deletedItem);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
