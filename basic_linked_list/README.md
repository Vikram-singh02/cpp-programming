# Basic Linked List Implementation

This is a comprehensive implementation of a singly linked list data structure in C++. The project demonstrates various operations on a linked list with an interactive menu system and robust error handling.

## Features

### Basic Operations
- Insert elements at the front of the list
- Insert elements at the end of the list
- Delete elements by value
- Display the entire list

### Advanced Features
- Search for elements in the list
- Get the current size of the list
- Interactive menu system
- Input validation and error handling
- Memory allocation error handling
- Informative operation feedbacknked List Implementation in C++

This is a simple implementation of a singly linked list data structure in C++. The project demonstrates basic operations on a linked list including insertion, deletion, and traversal.

## Features

- Insert elements at the front of the list
- Insert elements at the end of the list
- Delete elements by value
- Display the entire list

## Project Structure

```
basic_linked_list/
├── LinkedList.h    # Header file containing the LinkedList class definition
├── main.cpp       # Main program file with implementation and test code
├── Makefile      # Build configuration
└── README.md     # This file
```

## Requirements

- C++ compiler (g++)
- Make build system

## Building the Project

To build the project, run:
```bash
make
```

To clean the build files:
```bash
make clean
```

To rebuild from scratch:
```bash
make clean && make
```

## Running the Program

After building, run the program with:
```bash
./linkedlist
```

## Interactive Menu Options

The program provides an interactive menu with the following options:
1. Insert Value at front
2. Insert Value at end
3. Delete Value
4. Display List
5. Search Value
6. Get List Size
7. Exit

## Error Handling

The program includes comprehensive error handling for:
- Invalid menu choices
- Non-numeric input
- Memory allocation failures
- Empty list operations
- Value not found in list

## Sample Output

```
=== Linked List Operations ===
1. Insert Value at front
2. Insert Value at end
3. Delete Value
4. Display List
5. Search Value
6. Get List Size
7. Exit

Enter your choice (1-7): 1
Enter value to insert at front: 10
Value 10 inserted at front successfully!

Current List: 10 -> NULL

Enter your choice (1-7): 5
Enter value to search: 10
Value 10 found in the list!
```


## Implementation Details

### LinkedList Class
The `LinkedList` class provides the following methods:
- `insertFront(int value)`: Inserts a new node at the beginning
- `insertEnd(int value)`: Inserts a new node at the end
- `deleteNode(int value)`: Deletes the first occurrence of a value
- `display()`: Prints the list contents

### Node Structure
Each node in the list contains:
- An integer data value
- A pointer to the next node

## Future Enhancements
Possible improvements that could be added:
- Searching for elements
- Inserting at a specific position
- Getting the list size
- Reversing the list
- Sorting capabilities
