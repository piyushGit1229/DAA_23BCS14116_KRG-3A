// piyush kumar varma uid 23bcs14116

#include <iostream>

using namespace std;

struct CNode {
    int data;
    CNode* next;

    CNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

CNode* head = nullptr;

void insertBegin(int val) {
    CNode* newNode = new CNode(val);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertEnd(int val) {
    CNode* newNode = new CNode(val);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void deleteBegin() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == head) {
        head = nullptr;
        cout << "Deleted last node." << endl;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    head = head->next;
    temp->next = head;
    cout << "Deleted from beginning." << endl;
}

void deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == head) {
        head = nullptr;
        cout << "Deleted last node." << endl;
        return;
    }
    CNode* temp = head;
    while (temp->next->next != head) temp = temp->next;
    temp->next = head;
    cout << "Deleted from end." << endl;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    CNode* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n--- Circular Linked List Menu ---" << endl;
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
