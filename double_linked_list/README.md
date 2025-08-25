# Double Linked List Implementation

This is a comprehensive implementation of a doubly linked list data structure in C++. The project demonstrates various operations on a double linked list with an interactive menu system, robust error handling, and additional functionality compared to a single linked list.

## Features

### Basic Operations
- Insert elements at the front of the list
- Insert elements at the end of the list
- Insert elements at a specific position
- **NEW:** Insert elements after a specific value
- Delete elements by value
- Delete elements at a specific position
- Display the entire list (forward direction)
- **NEW:** Display the entire list (backward direction)

### Advanced Features
- Search for elements in the list
- Get the current size of the list
- Check if the list is empty
- Clear the entire list
- Interactive menu system with 13 different operations
- Input validation and comprehensive error handling
- Memory allocation error handling
- Informative operation feedback with emojis

## Project Structure

```
double_linked_list/
├── DoubleLinkedList.h    # Header file containing the DoubleLinkedList class definition
├── main.cpp              # Main program file with implementation and interactive menu
├── Makefile             # Build configuration
├── test.sh              # Automated test suite
└── README.md            # This file
```

## Key Differences from Single Linked List

1. **Bidirectional Navigation**: Each node has both `next` and `prev` pointers
2. **Reverse Display**: Can traverse and display the list in both directions
3. **Insert After Value**: New feature to insert a value after a specific existing value
4. **Enhanced Operations**: More efficient deletion and insertion operations
5. **Tail Pointer**: Maintains both head and tail pointers for O(1) end operations

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
./double_linkedlist
```

## Interactive Menu Options

The program provides an interactive menu with the following options:
1. Insert Value at front
2. Insert Value at end
3. Insert Value at position
4. **Insert Value after specific value** (NEW)
5. Delete Value
6. Delete Value at position
7. Display List (Forward)
8. **Display List (Backward)** (NEW)
9. Search Value
10. Get List Size
11. Check if List is Empty
12. Clear List
13. Exit

## Running Tests

Execute the automated test suite:
```bash
./test.sh
```

## Error Handling

The program includes comprehensive error handling for:
- Invalid menu choices
- Non-numeric input
- Memory allocation failures
- Empty list operations
- Value not found in list
- Position out of bounds
- Negative positions

## Sample Output

```
🔗 Welcome to Double Linked List Program! 🔗
==========================================

=== Double Linked List Operations ===
1.  Insert Value at front
2.  Insert Value at end
3.  Insert Value at position
4.  Insert Value after specific value
5.  Delete Value
6.  Delete Value at position
7.  Display List (Forward)
8.  Display List (Backward)
9.  Search Value
10. Get List Size
11. Check if List is Empty
12. Clear List
13. Exit

Enter your choice (1-13): 1
Enter value to insert at front: 10
✅ Value 10 inserted at front successfully!

Enter your choice (1-13): 7
📋 List (Head to Tail): 10 -> NULL

Enter your choice (1-13): 8
📋 List (Tail to Head): 10 -> NULL
```

## Implementation Details

### Node Structure
Each node contains:
- An integer data value
- A pointer to the next node (`next`)
- A pointer to the previous node (`prev`)

### DoubleLinkedList Class
The `DoubleLinkedList` class provides:
- Private `head` and `tail` pointers
- Comprehensive public methods for all operations
- Proper memory management with destructor

## Future Enhancements
Possible improvements that could be added:
- Template-based implementation for different data types
- Iterator support
- Sorting capabilities
- Merge operations
- Split operations
