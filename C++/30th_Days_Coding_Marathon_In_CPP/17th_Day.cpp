//1) Given a pointer to the head node of a doubly linked list and two keys, x and y respectively, swap these two nodes of the list (if these nodes exists in the list).

// Note: All the linked list nodes contain distinct data.

// Complete the function swapNodes(), which takes the head node of a doubly linked list along with x and y as a parameter, and returns the head of updated list after swapping the two nodes.

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
//     Node(int val) : data(val), next(nullptr), prev(nullptr) {}
// };

// Node* swapNodes(Node* head, int x, int y) {
//     if (!head || x == y) return head;
    
//     Node *nodeX = nullptr, *nodeY = nullptr, *temp = head;
    
//     while (temp) {
//         if (temp->data == x) nodeX = temp;
//         if (temp->data == y) nodeY = temp;
//         temp = temp->next;
//     }
    
//     if (!nodeX || !nodeY) return head;
    
//     if (nodeX->prev) nodeX->prev->next = nodeY;
//     if (nodeY->prev) nodeY->prev->next = nodeX;
    
//     if (nodeX->next) nodeX->next->prev = nodeY;
//     if (nodeY->next) nodeY->next->prev = nodeX;
    
//     swap(nodeX->prev, nodeY->prev);
//     swap(nodeX->next, nodeY->next);
    
//     if (head == nodeX) head = nodeY;
//     else if (head == nodeY) head = nodeX;
    
//     return head;
// }

// void printList(Node* head) {
//     while (head) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// Node* insert(Node* head, int data) {
//     Node* newNode = new Node(data);
//     if (!head) return newNode;
//     Node* temp = head;
//     while (temp->next) temp = temp->next;
//     temp->next = newNode;
//     newNode->prev = temp;
//     return head;
// }

// int main() {
//     int n, x, y;
//     cin >> n;
//     Node* head = nullptr;
//     for (int i = 0; i < n; i++) {
//         int val;
//         cin >> val;
//         head = insert(head, val);
//     }
//     cin >> x >> y;
//     head = swapNodes(head, x, y);
//     printList(head);
//     return 0;
// }


// 2)Aim: Rearrange the Even-Odd Nodes of Doubly Linked List
// Given a pointer to the head node of a doubly linked list, rearrange the nodes of list such that
// all even positioned nodes are shifted before odd positioned nodes while keeping their relative
// order same as in the original list.
// Note: The head node of the list is at position 1 i.e. odd position
// Complete the function rearrangeList(), which takes the head node of a doubly linked list as
// a parameter, and returns the head of updated list after rearranging it.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* rearrangeList(Node* head) {
    if (!head || !head->next) return head;
    
    Node *evenHead = nullptr, *evenTail = nullptr;
    Node *oddHead = nullptr, *oddTail = nullptr;
    
    Node* current = head;
    int position = 1;
    
    while (current) {
        Node* nextNode = current->next;
        current->next = current->prev = nullptr;
        
        if (position % 2 == 0) {
            if (!evenHead) evenHead = evenTail = current;
            else {
                evenTail->next = current;
                current->prev = evenTail;
                evenTail = current;
            }
        } else {
            if (!oddHead) oddHead = oddTail = current;
            else {
                oddTail->next = current;
                current->prev = oddTail;
                oddTail = current;
            }
        }
        position++;
        current = nextNode;
    }
    
    if (!evenHead) return head;
    
    evenTail->next = oddHead;
    oddHead->prev = evenTail;
    
    return evenHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* head = nullptr;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            head = insert(head, val);
        }
        head = rearrangeList(head);
        printList(head);
    }
    return 0;
}
