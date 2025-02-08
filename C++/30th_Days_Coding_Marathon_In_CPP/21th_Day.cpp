//1) Find the kth smallest element in the binary search tree
// Given a binary search tree and a number k, print the kth smallest number in tree.
// Input
// The root node of binary search tree is given to you. Do not write the whole program, just complete the function int kSmallest(Node root, int k) which takes the address of the root node of tree and an integer k as parameters and return the kth smallest number from tree.
// Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.
// Output
// Print the kth smallest number from the binary search tree.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void inorder(Node* root, int &k, int &result) {
    if (!root || k == 0) return;

    inorder(root->left, k, result);
    
    k--;
    if (k == 0) {
        result = root->data;
        return;
    }

    inorder(root->right, k, result);
}

int kSmallest(Node* root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 8);

    int k1 = 4, k2 = 6;
    
    cout << "4th smallest element: " << kSmallest(root, k1) << endl;
    cout << "6th smallest element: " << kSmallest(root, k2) << endl;

    return 0;
}

// 2) Print all paths to leaves and their details of a binary tree
// Given a binary tree print all paths from root node to leaf nodes with their respective lengths and total number of paths in it.
// The root node of binary tree is given to you. A path from root to leaf in a tree is a sequence of adjacent nodes from root to any leaf node.
// Do not write the whole program, just complete the function void printAllPaths(Node root) which takes the address of the root as a parameter and print all details as shown below.
// Note: If the tree is empty, do not print anything.
// Input Format
// First line contains an integer N, denoting the number of integers to follow in the serialized representation of the tree.
// Second line contains N space separated integers, denoting the level order description of left and right child of nodes, where -1 signifies a NULL child.
// Output
// For each test case, print the paths with their length and total paths in new lines.


// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
    
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// void findPaths(Node* root, vector<int>& path, int& count) {
//     if (!root) return;

//     path.push_back(root->data);

//     if (!root->left && !root->right) { 
//         for (int val : path) cout << val << " ";
//         cout << path.size() - 1 << endl;
//         count++;
//     } else {
//         findPaths(root->left, path, count);
//         findPaths(root->right, path, count);
//     }

//     path.pop_back(); 
// }

// void printAllPaths(Node* root) {
//     if (!root) return;

//     vector<int> path;
//     int count = 0;
    
//     findPaths(root, path, count);

//     cout << count << endl; 
// }

// Node* buildTree(vector<int>& nodes) {
//     if (nodes.empty() || nodes[0] == -1) return nullptr;

//     queue<Node*> q;
//     Node* root = new Node(nodes[0]);
//     q.push(root);

//     int i = 1;
//     while (!q.empty() && i < nodes.size()) {
//         Node* curr = q.front();
//         q.pop();

//         if (nodes[i] != -1) {
//             curr->left = new Node(nodes[i]);
//             q.push(curr->left);
//         }
//         i++;

//         if (i < nodes.size() && nodes[i] != -1) {
//             curr->right = new Node(nodes[i]);
//             q.push(curr->right);
//         }
//         i++;
//     }
//     return root;
// }

// int main() {
//     int N;
//     cin >> N;
//     vector<int> nodes(N);

//     for (int i = 0; i < N; i++)
//         cin >> nodes[i];

//     Node* root = buildTree(nodes);

//     printAllPaths(root);

//     return 0;
// }
