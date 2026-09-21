# Sorting Algorithms

This folder contains implementations of common sorting algorithms in C++.

## Algorithms

| Algorithm      |       Best |    Average |      Worst |     Space |
| -------------- | ---------: | ---------: | ---------: | --------: |
| Bubble Sort    |      O(n²) |      O(n²) |      O(n²) |      O(1) |
| Selection Sort |      O(n²) |      O(n²) |      O(n²) |      O(1) |
| Insertion Sort |       O(n) |      O(n²) |      O(n²) |      O(1) |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) |      O(n) |
| Quick Sort     | O(n log n) | O(n log n) |      O(n²) |      O(n) |


---

## Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them when they are in the wrong order.

After each pass, the largest unsorted element moves to the end of the array. The process continues until all elements are sorted.

**Example:**

```text
[5, 3, 8, 1]

Compare 5 and 3 → swap
[3, 5, 8, 1]

Compare 5 and 8 → no swap
[3, 5, 8, 1]

Compare 8 and 1 → swap
[3, 5, 1, 8]
```

After the first pass, `8` is in its correct position. The remaining elements are processed in the same way.

**Complexity:**

* Best: O(n²)
* Average: O(n²)
* Worst: O(n²)
* Space: O(1)

---

## Selection Sort

Selection Sort divides the array into a sorted part and an unsorted part.

For each position, it searches the unsorted part for the smallest element and swaps it with the first element of the unsorted part.

**Example:**

```text
[5, 3, 8, 1]

Find minimum → 1
Swap with first element

[1, 3, 8, 5]
```

Now `1` is in its correct position. The algorithm repeats the same process for the remaining elements.

**Complexity:**

* Best: O(n²)
* Average: O(n²)
* Worst: O(n²)
* Space: O(1)

---

## Insertion Sort

Insertion Sort builds the sorted array one element at a time.

It takes the next element and inserts it into its correct position among the elements that are already sorted.

**Example:**

```text
[5, 3, 8, 1]

Take 3:
[3, 5, 8, 1]

Take 8:
[3, 5, 8, 1]

Take 1:
[1, 3, 5, 8]
```

The elements greater than the current element are shifted to the right to make space for it.

**Complexity:**

* Best: O(n)
* Average: O(n²)
* Worst: O(n²)
* Space: O(1)

---

## Merge Sort

Merge Sort uses the **Divide and Conquer** approach.

It repeatedly divides the array into smaller halves until each part contains one element. Then, it merges the smaller sorted parts together to produce the final sorted array.

**Example:**

```text
[8, 3, 5, 1]

Divide:
[8, 3] [5, 1]

Divide again:
[8] [3] [5] [1]

Merge:
[3, 8] [1, 5]

Final merge:
[1, 3, 5, 8]
```

The merging step compares elements from the two sorted parts and places them in the correct order.

**Complexity:**

* Best: O(n log n)
* Average: O(n log n)
* Worst: O(n log n)
* Space: O(n)

---

## Quick Sort

Quick Sort also uses the **Divide and Conquer** approach.

It selects an element as a **pivot**, then rearranges the array so that:

* Elements smaller than the pivot are placed before it.
* Elements greater than or equal to the pivot are placed after it.

The same process is then applied recursively to the two resulting parts.

**Example:**

```text
[5, 3, 8, 1, 4]

Choose 4 as pivot:

[3, 1] 4 [5, 8]
```

Then Quick Sort is applied to:

```text
[3, 1]
```

and

```text
[5, 8]
```

until the whole array is sorted.

In this implementation, the last element is chosen as the pivot.

**Complexity:**

* Best: O(n log n)
* Average: O(n log n)
* Worst: O(n²)
* Average Space: O(log n)
* Worst Space: O(n)

---

## Notes

* All implementations are written from scratch in C++.
* The algorithms were implemented for learning and practice.
* Each implementation was tested with different input cases.
