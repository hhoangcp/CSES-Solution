# Distinct Numbers - Solution

**ID:** 1621 | **URL:** https://cses.fi/problemset/task/1621

## Approach

### Problem Restatement

Given an array of $n$ integers, count the number of distinct values.

### Core Idea

A `set` in C++ is a balanced BST that rejects duplicate elements. After inserting all $n$ elements, `S.size()` equals the number of distinct values. This is correct because: every distinct value appears at least once so it gets inserted ($V \subseteq S$), and `set` only contains values from the input ($S \subseteq V$), hence $S = V$.

Alternative: sort the array and count how many times the current element differs from the previous one — also $O(n \log n)$ but with better cache locality.

### Algorithm

1. Initialize `set<int> S`.
2. Read each element and insert into `S`.
3. Output `S.size()`.

### Example

Array $[2, 3, 2, 2, 3]$.

| Step | Element | $S$ | Note |
|------|---------|-----|------|
| 1 | 2 | $\{2\}$ | New |
| 2 | 3 | $\{2, 3\}$ | New |
| 3 | 2 | $\{2, 3\}$ | Duplicate |
| 4 | 2 | $\{2, 3\}$ | Duplicate |
| 5 | 3 | $\{2, 3\}$ | Duplicate |

Result: $|S| = \mathbf{2}$.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Distinct%20Numbers.cpp)
