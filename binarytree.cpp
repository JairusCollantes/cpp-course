#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 1. Inorder Traversal: Left -> Root -> Right
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// 2. Preorder Traversal: Root -> Left -> Right
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 3. Postorder Traversal: Left -> Right -> Root
void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// 4. Level-Order Traversal (BFS): Uses a queue
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

int main() {
    // Construct a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder:     ";
    inorderTraversal(root);     // Output: 4 2 5 1 3
    cout << "\n";

    cout << "Preorder:    ";
    preorderTraversal(root);    // Output: 1 2 4 5 3
    cout << "\n";

    cout << "Postorder:   ";
    postorderTraversal(root);   // Output: 4 5 2 3 1
    cout << "\n";

    cout << "Level-Order: ";
    levelOrderTraversal(root);  // Output: 1 2 3 4 5
    cout << "\n";

    return 0;
}
