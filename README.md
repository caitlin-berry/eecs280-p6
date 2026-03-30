# Project 6 - Binary Search Tree Map

## Overview
This project implements a map container in C++ built on top of a binary search tree (BST) data structure.

The project focuses on designing and implementing a reusable, generic data structure using templates, recursion, and functors. The map behaves similarly to std::map, storing key-value pairs and supporting efficient lookup, insertion, and traversal.

## Features
- Custom implementation of a **Binary Search Tree**
- No duplicate elements allowed (enforces BST invariant)
- Recursive implementation of core operations
- Template-based design supporting generic types
- Custom comparator support using functors
- Implementation of a **Map ADT** using the BST
- Key-value storage using std::pair
- Iterator support for traversal
- Supports:
  - insert
  - find
  - operator[]
  - traversal using iterators

## Binary Search Tree
- Each node contains:
  - data
  - pointer to left child
  - pointer to right child
- Maintains the **sorting invariant**:
  - left subtree values < node
  - right subtree values > node 
- Enables efficient search and insertion (logarithmic time in balanced cases)

## Map Implementation
- Built using a **"has-a" relationship** with the BST 
- Stores elements as key-value pairs:
  - std::pair<Key, Value>
- Uses a custom comparator to compare keys only
- Mimics behavior of std::map:
  - inserting pairs
  - accessing values with []
  - automatically inserting default values when needed

## How to Run

Compile using the provided Makefile:
```bash
make
```
Run Binary Search Tree tests:
``` bash
./BinarySearchTree_tests.exe
```
Run Map tests:
``` bash
./Map_tests.exe
```
Run public tests:
``` bash
./BinarySearchTree_public_tests.exe
./Map_public_tests.exe
```

## Program Structure
- `BinarySearchTree.hpp` – BST implementation (core recursive logic)
- `BinarySearchTree_tests.cpp` – unit tests for BST
- `Map.hpp` – map implementation using BST
- `Map_tests.cpp` – unit tests for map (optional submission)
- `TreePrint.hpp` – helper for visualizing trees
- `unit_test_framework.hpp` – testing framework
- `Makefile` – build commands

## Concepts Used
- Binary search trees
- Recursion (no loops in core BST functions)
- Templates and generic programming
- Functors (custom comparators)
- Iterators and traversal
- Associative containers
- Key-value data structures
- Unit testing and test design

## How It Works
1. Binary Search Tree
   - Recursively inserts elements while maintaining ordering
   - Navigates left or right depending on comparisons
   - Base case handles empty subtree

2. Map Layer
   - Wraps BST storing std::pair<Key, Value>
   - Uses comparator that compares only keys
   - Reuses BST iterators for traversal

3. Key Operations
   - insert → adds key-value pair if not present
   - find → returns iterator to matching key
   - operator[] → returns reference to value, inserting default if missing

## Example Usage
``` c++
Map<string, int> word_count;

word_count["hello"] = 1;
word_count["world"] = 2;

for (const auto &kv : word_count) {
    cout << kv.first << " " << kv.second << endl;
}
```

## Notes
- All BST operations are implemented recursively (no loops allowed)
- Efficient design relies on maintaining the BST invariant
- Duplicate keys are not allowed
- Map functionality is built by reusing BST logic
- Designed to mirror behavior of std::map while implementing underlying data structure manually
