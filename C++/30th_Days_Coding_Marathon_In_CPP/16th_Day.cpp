//1) Find the loop in Linked list : 
//          A linked list is a collection of nodes stored in memory through pointers. These pointers may or may not be replicated, which might result in a loop of nodes.
// Given a linked-list as input, check whether it contains a loop or not. If there is a loop return the number of nodes in the loop, otherwise return 0.
// Complete the function loopInList() which takes the head node of a linked list as a parameter, and returns the number of nodes in loop if exists, 0 otherwise.

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int val) : data(val), next(nullptr) {}
// };

// void createLoop(Node* head, int pos) {
//     if (pos == -1) return;
//     Node* temp = head;
//     Node* loopNode = nullptr;
//     int count = 1;
//     while (temp->next) {
//         if (count == pos) {
//             loopNode = temp;
//         }
//         temp = temp->next;
//         count++;
//     }
//     if (loopNode) {
//         temp->next = loopNode;
//     }
// }

// int countLoopNodes(Node* slow) {
//     Node* temp = slow;
//     int count = 1;
//     while (temp->next != slow) {
//         temp = temp->next;
//         count++;
//     }
//     return count;
// }

// int loopInList(Node* head) {
//     if (!head) return 0;
    
//     Node *slow = head, *fast = head;
//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
        
//         if (slow == fast) {
//             return countLoopNodes(slow);
//         }
//     }
//     return 0;
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         int N;
//         cin >> N;
        
//         Node* head = nullptr;
//         Node* tail = nullptr;
//         for (int i = 0; i < N; i++) {
//             int val;
//             cin >> val;
//             Node* newNode = new Node(val);
//             if (!head) {
//                 head = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//         }
        
//         int loopPos;
//         cin >> loopPos;
//         createLoop(head, loopPos);
        
//         cout << loopInList(head) << endl;
//     }
//     return 0;
// }



// 2) Delete in Circular Linked List bookmark_border : 
//   Given a pointer to the head node of a circular linked list, delete the nodes from beginning or end.
// Complete the functions deleteBeg() & deleteEnd() that takes the head node of a linked list as parameters delete the specified node and return the new head.
// Note: Do not read any input from stdin/console. Each test case calls the deleteBeg & deleteEnd method individually and passes it the head of a list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* deleteBeg(Node* head) {
    if (!head) return nullptr;
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    head = head->next;
    last->next = head;
    delete temp;
    return head;
}

Node* deleteEnd(Node* head) {
    if (!head) return nullptr;
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    delete temp;
    return head;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < N; i++) {
        int val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
        }
        tail = newNode;
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        int query;
        cin >> query;
        if (query == 1) {
            head = deleteBeg(head);
        } else if (query == 2) {
            head = deleteEnd(head);
        }
    }
    
    printList(head);
    return 0;
}
