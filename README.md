# Data Structures Lab Experiments

This repository contains implementations of various data structures and algorithms as part of the Data Structures Lab course.

## Experiments

1. **Tower of Hanoi using Stack**: Implementation of the Tower of Hanoi problem using Stack data structure.
2. **Stack Operations**: Menu-driven program for performing Push and Pop operations on a Stack.
3. **Infix to Postfix**: Program to transform infix expressions to postfix expressions.
4. **Circular Queue**: Menu-driven program for performing Insertion and Deletion operations on a Circular Queue.
5. **Singly Linked List**: Menu-driven program for performing various operations on a Singly Linked List.
6. **Binary Search Tree (BST)**: Menu-driven program for creating, traversing, and deleting elements from a BST.
7. **Graph Traversal**: Program for performing BFS and DFS traversal on a Graph.
8. **Binary Search**: Implementation of the Binary Search algorithm.
9. **Hashing**: Program to search elements using Hashing with Linear Probing.
10. **Case Study**: A comprehensive Student Database Management System using various data structures.

## Requirements

- GCC Compiler
- Make (optional, for using the makefile)

## How to Compile

You can compile all programs at once using the provided makefile:

```bash
make all
```

To compile a specific experiment, use:

```bash
make exp<number>
```

For example, to compile Experiment 1:

```bash
make exp1
```

## How to Run

After compiling, you can run the programs using:

```bash
./exp<number>
```

For example, to run Experiment 1:

```bash
./exp1
```

Alternatively, you can use the makefile to run specific experiments:

```bash
make run_exp<number>
```

For example:

```bash
make run_exp1
```

## Cleaning Up

To remove all compiled executables:

```bash
make clean
```

## Program Descriptions

### Experiment 1: Tower of Hanoi using Stack
Implements the Tower of Hanoi problem using both recursive and iterative (with stack) approaches.

### Experiment 2: Stack Operations
Provides a menu to perform push and pop operations on a stack, along with a display function.

### Experiment 3: Infix to Postfix
Converts infix expressions to postfix expressions using stack data structure.

### Experiment 4: Circular Queue
Implements insertion and deletion operations on a circular queue.

### Experiment 5: Singly Linked List
Implements insertion and deletion operations at the beginning, end, and specific positions in a singly linked list.

### Experiment 6: Binary Search Tree
Creates a BST and performs traversals (Inorder, Preorder, Postorder) and deletion operations.

### Experiment 7: Graph Traversal
Implements BFS and DFS traversal algorithms on a graph represented using an adjacency matrix.

### Experiment 8: Binary Search
Implements the binary search algorithm using both iterative and recursive approaches.

### Experiment 9: Hashing with Linear Probing
Implements a hash table with linear probing for collision resolution.

### Experiment 10: Case Study
A comprehensive Student Database Management System that uses various data structures and algorithms. 