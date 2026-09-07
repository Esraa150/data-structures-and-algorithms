# Doubly Linked List

A **Doubly Linked List** is a linear data structure where each node contains:

* Data
* A pointer to the next node
* A pointer to the previous node

The list maintains pointers to both the **head** and **tail**, as well as its current **size**.

## Features

* Add element to the front
* Add element to the back
* Remove element from the front
* Remove element from the back
* Access an element by index
* Insert an element at a specific index
* Find an element
* Clear the list
* Get the first and last elements
* Get the list size
* Check if the list is empty

## Time Complexity

| Operation       | Complexity |
| --------------- | ---------: |
| `empty()`       |       O(1) |
| `size()`        |       O(1) |
| `front()`       |       O(1) |
| `back()`        |       O(1) |
| `addFront()`    |       O(1) |
| `removeFront()` |       O(1) |
| `addBack()`     |       O(1) |
| `removeBack()`  |       O(1) |
| `at()`          |       O(n) |
| `find()`        |       O(n) |
| `insert()`      |       O(n) |

## Implementation

Each node stores pointers to both the **next** and **previous** nodes, allowing traversal in both directions.

The list maintains `head`, `tail`, and `n` to efficiently manage the structure and provide constant-time access to the first and last elements.

