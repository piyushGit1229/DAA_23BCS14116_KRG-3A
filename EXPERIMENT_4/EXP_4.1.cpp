// piyush kumar varma uid 23bcs14116

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node* head = nullptr;

void insertBegin(int val) {
    Node* newNode = new Node(val);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteBegin() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    cout << "Deleted from beginning." << endl;
}

void deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == nullptr) {
        head = nullptr;
        cout << "Deleted from end." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->prev->next = nullptr;
    cout << "Deleted from end." << endl;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete at Beginning" << endl;
        cout << "4. Delete at End" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBegin(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                deleteBegin();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
