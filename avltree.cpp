
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;

    Node(int x) : key(x), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int balance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balance(root);

    if (b > 1 && key < root->left->key)
        return rightRotate(root);       // LL

    if (b < -1 && key > root->right->key)
        return leftRotate(root);        // RR

    if (b > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);       // LR
    }

    if (b < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);        // RL
    }

    return root;
}

void preorder(Node* root) {
    if (!root)
        return;

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;

    int values[] = {10, 20, 30, 40, 50, 25};

    for (int x : values)
        root = insert(root, x);

    cout << "Preorder traversal of AVL tree: ";
    preorder(root);

    return 0;
}
