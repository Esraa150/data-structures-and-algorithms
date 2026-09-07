# ArrayVector

A simple implementation of a dynamic array in C++ using templates and dynamic memory allocation.

## Features

* `size()`
* `empty()`
* `operator[]`
* `at()`
* `front()`
* `back()`
* `push_back()`
* `pop_back()`
* `insert()`
* `erase()`
* `clear()`
* `reserve()`

## How it works

The array starts with a capacity of 100 elements.

When the array becomes full, its capacity is doubled and the existing elements are copied to the new array.

## Time Complexity

| Operation     | Complexity     |
| ------------- | -------------- |
| Access        | O(1)           |
| `push_back()` | O(1) amortized |
| `pop_back()`  | O(1)           |
| `insert()`    | O(n)           |
| `erase()`     | O(n)           |
| `reserve()`   | O(n)           |
| `clear()`     | O(1)           |


## Purpose

This implementation was created to practice dynamic arrays, templates, pointers, memory management, and time complexity.
