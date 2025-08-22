#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    
    // Function to insert a new node at the beginning
    void insertFront(int value);
    
    // Function to insert a new node at the end
    void insertEnd(int value);
    
    // Function to delete a node with given value
    void deleteNode(int value);
    
    // Function to display the list
    void display();
    
    // Function to search for a value in the list
    bool search(int value);
    
    // Function to get the current size of the list
    int size() const;
    
    // Destructor to free memory
    ~LinkedList();
};

#endif // LINKEDLIST_H
