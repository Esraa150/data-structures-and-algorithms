# Binary Tree

A simple template-based Binary Tree implementation in C++.

## Features

* Add a root node
* Add left and right children
* Access parent, left child, and right child
* Access and modify node elements
* Remove external (leaf) nodes
* Clear the tree
* Check if the tree is empty
* Get the tree size
* Tree traversals:

  * Preorder
  * Inorder
  * Postorder
* Exception handling for invalid operations

## Implementation

The tree is implemented using nodes containing:

* `data`
* `left` pointer
* `right` pointer
* `parent` pointer

Each node keeps a pointer to its parent, making it possible to move between parents and children.

## Example Tree

```text
       1
      / \
     2   3
    / \
   4   5
```

### Traversals

```text
Preorder:  1 2 4 5 3
Inorder:   4 2 5 1 3
Postorder: 4 5 2 3 1
```


## Notes

This implementation is intended for learning and practicing Binary Tree data structures and their basic operations in C++.
