// 1) Complete the inorder(), preorder() and postorder() functions for traversal with recursion bookmark_border
//  Given a binary tree, print it in inorder, preorder and postorder fashion with recursion.
//  Input
//  The root node of binary tree is given to you, and you have to complete the function
//  void inorder(Node root), void preorder(Node root) & void postorder(Node root)
//  to print the nodes of tree. (The function should use recursion).
//  Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.
//  Output
//  Print the nodes of tree separated by space by all three traversals in new lines.

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node *left, *right;

//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// void inorder(Node* root) {
//     if (root == nullptr) return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// void preorder(Node* root) {
//     if (root == nullptr) return;
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }

// void postorder(Node* root) {
//     if (root == nullptr) return;
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);

//     inorder(root);
//     cout << endl;

//     preorder(root);
//     cout << endl;

//     postorder(root);
//     cout << endl;
//     return 0;
// }

// 2)  Construct tree from given inorder and post order traversal bookmark_border
//  Given two array representing the inorder and postorder traversal of a binary tree, construct the tree and return its root node.
//  Input
//  Two arrays for traversals and total number of nodes are given and you needs to write a function Node buildTree(int in[], int post[], int N), which accepts the inorder and postorder traversals of a binary tree and the number of nodes in the tree. The function returns the root node of the constructed tree.
//  Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.
//  Output
//  The nodes of tree will be printed separated by space using preorder traversal in new lines.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *newNode(int data)
{
    return new Node(data);
}

int search(int in[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == value)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int in[], int post[], int N)
{
    static int postIndex = N - 1;

    if (N <= 0)
        return nullptr;

    int current = post[postIndex];
    Node *node = newNode(current);
    postIndex--;

    if (N == 1)
        return node;

    int inIndex = search(in, 0, N - 1, current);

    node->right = buildTree(in + inIndex + 1, post, N - inIndex - 1);
    node->left = buildTree(in, post, inIndex);

    return node;
}

void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int N = 6;
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};

    Node *root = buildTree(inorder, postorder, N);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
