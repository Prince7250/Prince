//1) Complete the inorder(), preorder() and postorder() functions for traversal with recursion bookmark_border
// Given a binary tree, print it in inorder, preorder and postorder fashion with recursion.
// Input
// The root node of binary tree is given to you, and you have to complete the function
// void inorder(Node root), void preorder(Node root) & void postorder(Node root) 
// to print the nodes of tree. (The function should use recursion).
// Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.
// Output
// Print the nodes of tree separated by space by all three traversals in new lines.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    
    inorder(root);
    cout << endl;
    
    preorder(root);
    cout << endl;
    
    postorder(root);
    cout << endl;
    return 0;
}



