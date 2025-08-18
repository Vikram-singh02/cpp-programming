#include <iostream>
#include "LinkedList.h"

using namespace std;

// Implementation of LinkedList member functions
void LinkedList::insertFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertEnd(int value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::deleteNode(int value) {
    if (head == nullptr) return;
    
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Main function to test the LinkedList implementation
int main() {
    LinkedList list;
    char response = 'n';
    int choice, value;

    while(response != 'y') {
        cout << "\tEnter the your choice \n \
        Insert Value in front <1>\n \
        Insert Value in end <2>\n \
        Delete Value <3>\n \
        Display List <4>\n \
        Exit this loop <5>\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            list.insertFront(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertEnd(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 4:
            list.display();
            break;
        case 5:
            response = 'y';
            break;
        default:
            break;
        }
    }    
    return 0;
}
