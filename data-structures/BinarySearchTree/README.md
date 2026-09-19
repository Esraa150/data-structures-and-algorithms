# Binary Search Tree

A simple templated Binary Search Tree implementation in C++.

## Features

* Generic implementation using C++ templates
* Insert elements
* Search for elements
* Find minimum and maximum values
* Remove elements
* Clear the tree
* Check if the tree is empty
* Get tree size and root
* Preorder, Inorder, and Postorder traversals
* Duplicate values are ignored

## Structurefg

Each node contains:

* `data`
* `left` child
* `right` child

The tree maintains:

* A pointer to the root
* The number of elements

## Operations & Complexity

| Operation      |  Average | Worst Case |
| -------------- | -------: | ---------: |
| Insert         | O(log n) |       O(n) |
| Search         | O(log n) |       O(n) |
| Find Min / Max | O(log n) |       O(n) |
| Remove         | O(log n) |       O(n) |
| Traversal      |     O(n) |       O(n) |
| Clear          |     O(n) |       O(n) |

The average-case complexity assumes the tree is balanced. 

## Traversals

The implementation supports:

* **Preorder:** Root → Left → Right
* **Inorder:** Left → Root → Right
* **Postorder:** Left → Right → Root

For a valid BST, Inorder traversal visits the elements in sorted order.

## Example

Inserting:

```text
50, 30, 70, 20, 40, 60, 80
```

produces:

```text
        50
       /  \
     30    70
    / \    / \
   20 40  60 80
```

Inorder traversal:

```text
20 30 40 50 60 70 80
```
