#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
using namespace std;

// Node class for double linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    // Constructor
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Double Linked List class
class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoubleLinkedList();
    
    // Destructor
    ~DoubleLinkedList();
    
    // Basic operations
    void insertFront(int value);
    void insertEnd(int value);
    void insertAtPosition(int value, int position);
    void insertAfterValue(int newValue, int afterValue);
    bool deleteNode(int value);
    bool deleteAtPosition(int position);
    void display();
    void displayReverse();
    bool search(int value);
    int size();
    bool isEmpty();
    void clear();
    
    // Additional operations for double linked list
    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }
};

#endif // DOUBLE_LINKED_LIST_H
