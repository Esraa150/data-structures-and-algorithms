# Array Stack

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.

The stack is implemented using a dynamically allocated array and keeps track of the top element using an index.

## Features

* Push an element onto the stack
* Pop the top element
* Access the top element
* Get the stack size
* Check if the stack is empty
* Dynamically resize the underlying array

## Time Complexity

| Operation   |     Complexity |
| ----------- | -------------: |
| `empty()`   |           O(1) |
| `size()`    |           O(1) |
| `top()`     |           O(1) |
| `push()`    | O(1) amortized |
| `pop()`     |           O(1) |
| `reserve()` |           O(n) |

## Implementation

The stack uses a dynamic array and an index `t` to track the top element.

When the array becomes full, its capacity is increased and the existing elements are copied to the new array.

The `push()` operation is **O(1) amortized**, while resizing occasionally takes **O(n)**.
