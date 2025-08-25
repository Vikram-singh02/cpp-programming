#include "DoubleLinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

// Constructor
DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
DoubleLinkedList::~DoubleLinkedList() {
    clear();
}

// Insert at front
void DoubleLinkedList::insertFront(int value) {
    Node* newNode = nullptr;
    try {
        newNode = new Node(value);
    } catch (const std::bad_alloc& e) {
        cout << "❌ Error: Memory allocation failed!" << endl;
        return;
    }
    
    if (head == nullptr) {
        // Empty list
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << "✅ Value " << value << " inserted at front successfully!" << endl;
}

// Insert at end
void DoubleLinkedList::insertEnd(int value) {
    Node* newNode = nullptr;
    try {
        newNode = new Node(value);
    } catch (const std::bad_alloc& e) {
        cout << "❌ Error: Memory allocation failed!" << endl;
        return;
    }
    
    if (tail == nullptr) {
        // Empty list
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "✅ Value " << value << " inserted at end successfully!" << endl;
}

// Insert at specific position
void DoubleLinkedList::insertAtPosition(int value, int position) {
    if (position < 0) {
        cout << "❌ Error: Position cannot be negative!" << endl;
        return;
    }
    
    if (position == 0) {
        insertFront(value);
        return;
    }
    
    Node* newNode = nullptr;
    try {
        newNode = new Node(value);
    } catch (const std::bad_alloc& e) {
        cout << "❌ Error: Memory allocation failed!" << endl;
        return;
    }
    
    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "❌ Error: Position out of bounds!" << endl;
        delete newNode;
        return;
    }
    
    if (current == tail) {
        insertEnd(value);
        delete newNode;
        return;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    
    cout << "✅ Value " << value << " inserted at position " << position + 1 << " successfully!" << endl;
}

// Insert after a specific value
void DoubleLinkedList::insertAfterValue(int newValue, int afterValue) {
    if (head == nullptr) {
        cout << "❌ Error: List is empty! Cannot insert after value " << afterValue << endl;
        return;
    }
    
    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "❌ Error: Value " << afterValue << " not found in the list!" << endl;
        return;
    }
    
    Node* newNode = nullptr;
    try {
        newNode = new Node(newValue);
    } catch (const std::bad_alloc& e) {
        cout << "❌ Error: Memory allocation failed!" << endl;
        return;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        // Inserting after tail
        tail = newNode;
    }
    
    current->next = newNode;
    cout << "✅ Value " << newValue << " inserted after " << afterValue << " successfully!" << endl;
}

// Delete node with specific value
bool DoubleLinkedList::deleteNode(int value) {
    if (head == nullptr) {
        cout << "❌ Error: Cannot delete from empty list!" << endl;
        return false;
    }
    
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "❌ Error: Value " << value << " not found in the list!" << endl;
        return false;
    }
    
    // Update prev node's next pointer
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        // Deleting head
        head = current->next;
    }
    
    // Update next node's prev pointer
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        // Deleting tail
        tail = current->prev;
    }
    
    delete current;
    cout << "✅ Value " << value << " deleted successfully!" << endl;
    return true;
}

// Delete node at specific position
bool DoubleLinkedList::deleteAtPosition(int position) {
    if (position < 0) {
        cout << "❌ Error: Position cannot be negative!" << endl;
        return false;
    }
    
    if (head == nullptr) {
        cout << "❌ Error: Cannot delete from empty list!" << endl;
        return false;
    }
    
    Node* current = head;
    for (int i = 0; i < position && current != nullptr; i++) {
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "❌ Error: Position out of bounds!" << endl;
        return false;
    }
    
    int value = current->data;
    
    // Update prev node's next pointer
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        // Deleting head
        head = current->next;
    }
    
    // Update next node's prev pointer
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        // Deleting tail
        tail = current->prev;
    }
    
    delete current;
    cout << "✅ Value " << value << " at position " << position << " deleted successfully!" << endl;
    return true;
}

// Display list from head to tail
void DoubleLinkedList::display() {
    if (head == nullptr) {
        cout << "📋 List is empty." << endl;
        return;
    }
    
    cout << "📋 List (Head to Tail): ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

// Display list from tail to head
void DoubleLinkedList::displayReverse() {
    if (tail == nullptr) {
        cout << "📋 List is empty." << endl;
        return;
    }
    
    cout << "📋 List (Tail to Head): ";
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data;
        if (current->prev != nullptr) {
            cout << " <-> ";
        }
        current = current->prev;
    }
    cout << " -> NULL" << endl;
}

// Search for a value
bool DoubleLinkedList::search(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Get size of the list
int DoubleLinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Check if list is empty
bool DoubleLinkedList::isEmpty() {
    return head == nullptr;
}

// Clear the entire list
void DoubleLinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Main function with interactive menu
int main() {
    DoubleLinkedList list;
    char response = 'n';
    int choice, value, position, afterValue;

    cout << "🔗 Welcome to Double Linked List Program! 🔗" << endl;
    cout << "==========================================" << endl;

    while(response != 'y') {
        cout << "\n=== Double Linked List Operations ===\n";
        cout << "1.  Insert Value at front\n";
        cout << "2.  Insert Value at end\n";
        cout << "3.  Insert Value at position\n";
        cout << "4.  Insert Value after specific value\n";
        cout << "5.  Delete Value\n";
        cout << "6.  Delete Value at position\n";
        cout << "7.  Display List (Forward)\n";
        cout << "8.  Display List (Backward)\n";
        cout << "9.  Search Value\n";
        cout << "10. Get List Size\n";
        cout << "11. Check if List is Empty\n";
        cout << "12. Clear List\n";
        cout << "13. Exit\n";
        cout << "\nEnter your choice (1-13): ";
        
        if (!(cin >> choice)) {
            cout << "❌ Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                if (!(cin >> value)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.insertFront(value);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                if (!(cin >> value)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.insertEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                cout << "Enter position (0-based): ";
                if (!(cin >> position)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.insertAtPosition(value, position);
                break;

            case 4:
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                cout << "Enter value after which to insert: ";
                if (!(cin >> afterValue)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.insertAfterValue(value, afterValue);
                break;

            case 5:
                cout << "Enter value to delete: ";
                if (!(cin >> value)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.deleteNode(value);
                break;

            case 6:
                cout << "Enter position to delete (0-based): ";
                if (!(cin >> position)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                list.deleteAtPosition(position);
                break;

            case 7:
                list.display();
                break;

            case 8:
                list.displayReverse();
                break;

            case 9:
                cout << "Enter value to search: ";
                if (!(cin >> value)) {
                    cout << "❌ Invalid input. Please enter a number.\n";
                    clearInputBuffer();
                    break;
                }
                if (list.search(value)) {
                    cout << "✅ Value " << value << " found in the list!" << endl;
                } else {
                    cout << "❌ Value " << value << " not found in the list." << endl;
                }
                break;

            case 10:
                cout << "📊 Current list size: " << list.size() << " nodes" << endl;
                break;

            case 11:
                if (list.isEmpty()) {
                    cout << "📋 The list is empty." << endl;
                } else {
                    cout << "📋 The list is not empty." << endl;
                }
                break;

            case 12:
                list.clear();
                cout << "🗑️ List cleared successfully!" << endl;
                break;

            case 13:
                response = 'y';
                cout << "👋 Thank you for using the Double Linked List program!" << endl;
                break;

            default:
                cout << "❌ Invalid choice. Please enter a number between 1 and 13." << endl;
                break;
        }
    }    
    return 0;
}
