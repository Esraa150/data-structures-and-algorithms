# Array Queue

A Queue is a linear data structure that follows the **FIFO (First In, First Out)** principle.

This implementation uses a **circular array** to efficiently manage the queue without shifting elements after dequeue operations.

## Features

* `enqueue()` – Add an element to the rear.
* `dequeue()` – Remove the element from the front.
* `front()` – Access the first element.
* `back()` – Access the last element.
* `size()` – Return the number of elements.
* `empty()` – Check if the queue is empty.
* Circular array implementation using `f`, `r`, and `n`.

## Time Complexity

| Operation   | Time |
| ----------- | ---- |
| `enqueue()` | O(1) |
| `dequeue()` | O(1) |
| `front()`   | O(1) |
| `back()`    | O(1) |
| `size()`    | O(1) |
| `empty()`   | O(1) |

## Implementation Notes

* `f` points to the front element.
* `r` points to the next available position for insertion.
* `n` stores the number of elements.
* `% capacity` is used to wrap the indices around the array.
* The queue has a fixed capacity and throws an exception when it is full.

