
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

void insertAtBeginning(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int search(Node* head, int value) {
    int index = 0;

    for (Node* current = head;
         current != nullptr;
         current = current->next) {

        if (current->data == value)
            return index;

        index++;
    }

    return -1;
}

void display(Node* head) {
    cout << "List: NULL <-> ";

    for (Node* current = head;
         current != nullptr;
         current = current->next) {

        cout << current->data << " <-> ";
    }

    cout << "NULL" << endl;
}

void displayBackward(Node* tail) {
    cout << "Backward: ";

    for (Node* current = tail;
         current != nullptr;
         current = current->prev) {

        cout << current->data << " ";
    }

    cout << endl;
}

void deleteValue(Node*& head, Node*& tail, int value) {
    Node* current = head;

    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << value << " not found.\n";
        return;
    }

    if (current == head && current == tail) {
        head = tail = nullptr;
    }
    else if (current == head) {
        head = head->next;
        head->prev = nullptr;
    }
    else if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    cout << value << " deleted.\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtBeginning(head, tail, 5);

    display(head);
    displayBackward(tail);

    cout << "20 is at position " << search(head, 20) << "\n";

    deleteValue(head, tail, 10);
    display(head);

    return 0;
}
