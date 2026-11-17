
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {

    if (!root)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);

    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

bool search(Node* root, int key) {

    if (!root)
        return false;

    if (root->data == key)
        return true;

    return key < root->data
        ? search(root->left, key)
        : search(root->right, key);
}

void inorder(Node* root) {

    if (!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main() {

    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : values)
        root = insert(root, x);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nSearch 60: "
         << (search(root, 60) ? "Found" : "Not found");

    return 0;
}
