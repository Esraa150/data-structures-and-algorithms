# Deque

A simple implementation of a **Double-Ended Queue (Deque)** using a circular array in C++.

## Features

* Add elements from the front
* Add elements from the back
* Remove elements from the front
* Remove elements from the back
* Access the front element
* Access the back element
* Check if the deque is empty
* Get the current size
* Circular array with wrap-around support
* Fixed capacity of 100 elements

## Implementation

The deque uses:

* A dynamic array to store elements
* `f` to track the front position
* `r` to track the position where the next back element will be added
* `n` to track the number of elements
* Circular indexing using modulo `%`

## Time Complexity

| Operation       | Complexity |
| --------------- | ---------- |
| `addFront()`    | O(1)       |
| `addBack()`     | O(1)       |
| `removeFront()` | O(1)       |
| `removeBack()`  | O(1)       |
| `front()`       | O(1)       |
| `back()`        | O(1)       |
| `size()`        | O(1)       |
| `empty()`       | O(1)       |

