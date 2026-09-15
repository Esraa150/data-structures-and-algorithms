# Circularly Linked List

A Circularly Linked List is a linked list where the last node points back to the first node instead of `NULL`.

```text
[A] → [B] → [C]
 ↑           ↓
 └───────────┘
```

## Features

* `addFront()` – Add an element at the beginning.
* `addBack()` – Add an element at the end.
* `removeFront()` – Remove the first element.
* `removeBack()` – Remove the last element.
* `front()` – Access the first element.
* `back()` – Access the last element.
* `at()` – Access an element by index.
* `insert()` – Insert an element at a specific position.
* `find()` – Find an element.
* `size()` – Return the number of elements.
* `empty()` – Check if the list is empty.
* `clear()` – Remove all elements.

## Time Complexity

| Operation       | Time |
| --------------- | ---- |
| `empty()`       | O(1) |
| `size()`        | O(1) |
| `front()`       | O(1) |
| `back()`        | O(1) |
| `addFront()`    | O(1) |
| `removeFront()` | O(1) |
| `addBack()`     | O(1) |
| `removeBack()`  | O(n) |
| `at()`          | O(n) |
| `insert()`      | O(n) |
| `find()`        | O(n) |

## Implementation Notes

* `head` points to the first node.
* `tail` points to the last node.
* `tail->next` always points to `head`.
* Traversal stops when the current node reaches `head` again instead of `NULL`.
* `removeBack()` requires traversal to find the node before `tail`.

