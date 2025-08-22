#include <iostream>
#include <limits>
#include "LinkedList.h"

using namespace std;

// Implementation of LinkedList member functions
void LinkedList::insertFront(int value) {
    Node* newNode = nullptr;
    try {
        newNode = new Node(value);
    } catch (const std::bad_alloc& e) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertEnd(int value) {
    Node* newNode = nullptr;
    try {
        newNode = new Node(value);
    } catch (const std::bad_alloc& e) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    
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
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Value " << value << " deleted successfully!" << endl;
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
        cout << "Value " << value << " deleted successfully!" << endl;
    } else {
        cout << "Value " << value << " not found in the list!" << endl;
    }
}

void LinkedList::display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool LinkedList::search(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int LinkedList::size() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
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

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Main function to test the LinkedList implementation
int main() {
    LinkedList list;
    char response = 'n';
    int choice, value;

    while(response != 'y') {
        cout << "\n=== Linked List Operations ===\n";
        cout << "1. Insert Value at front\n";
        cout << "2. Insert Value at end\n";
        cout << "3. Delete Value\n";
        cout << "4. Display List\n";
        cout << "5. Search Value\n";
        cout << "6. Get List Size\n";
        cout << "7. Exit\n";
        cout << "\nEnter your choice (1-7): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                if (!(cin >> value)) {
                    cout << "Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.insertFront(value);
                cout << "Value " << value << " inserted at front successfully!\n";
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                if (!(cin >> value)) {
                    cout << "Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.insertEnd(value);
                cout << "Value " << value << " inserted at end successfully!\n";
                break;

            case 3:
                cout << "Enter value to delete: ";
                if (!(cin >> value)) {
                    cout << "Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.deleteNode(value);
                break;

            case 4:
                cout << "\nCurrent List: ";
                list.display();
                break;

            case 5:
                cout << "Enter value to search: ";
                if (!(cin >> value)) {
                    cout << "Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                if (list.search(value)) {
                    cout << "Value " << value << " found in the list!\n";
                } else {
                    cout << "Value " << value << " not found in the list.\n";
                }
                break;

            case 6:
                cout << "Current list size: " << list.size() << " nodes\n";
                break;

            case 7:
                response = 'y';
                cout << "Thank you for using the Linked List program!\n";
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                break;
        }
    }    
    return 0;
}
