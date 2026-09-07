# Singly Linked List

A **Singly Linked List** is a linear data structure where each node contains:

* Data
* A pointer to the next node

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
| `removeBack()`  |       O(n) |
| `at()`          |       O(n) |
| `find()`        |       O(n) |
| `insert()`      |       O(n) |

## Implementation

The implementation uses dynamically allocated nodes and maintains `head`, `tail`, and `n` to efficiently manage the list.

`removeBack()` remains **O(n)** because a singly linked list does not have a pointer to the previous node.


