# Basic Linked List Implementation in C++

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

## Sample Output

```
Initial list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
After deleting 3: 1 -> 2 -> 4 -> 5 -> NULL
After deleting 1: 2 -> 4 -> 5 -> NULL
After deleting 5: 2 -> 4 -> NULL
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
