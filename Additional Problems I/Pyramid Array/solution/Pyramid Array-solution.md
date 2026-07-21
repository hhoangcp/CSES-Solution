# Pyramid Array - Solution

**ID:** 1747 | **URL:** https://cses.fi/problemset/task/1747

## Problem Statement

Given an array of $n$ distinct integers, find the minimum number of adjacent swaps to transform it into a pyramid array (increasing then decreasing, or purely increasing/decreasing).

## Approach

### 1. Problem analysis

- **Pyramid array:** Has the form $x_1 < x_2 < \dots < x_k > x_{k+1} > \dots > x_n$.
- **Adjacent swap:** The minimum number of adjacent swaps to move an element to its correct position is proportional to the number of elements it must "cross through".
- **Greedy property:** In a pyramid array, the smallest elements reside at both ends (left or right) and progressively larger elements move toward the center (the peak). For each element, there are two choices: move it toward the left boundary or the right boundary.

### 2. Approach using Fenwick Tree (BIT)

To minimize the number of swaps, each element $a[i]$ chooses a direction (left or right) that minimizes the number of elements it must cross.

- **Step 1: Coordinate compression:** Since values $x_i$ can be up to $10^9$, sort the array and map each value to a rank from $1 \dots n$ for use with the BIT.
- **Step 2: Count larger elements to the left:** Scan left to right. For each element $a[i]$, the number of smaller elements already seen to the left is `Query(a[i])`. Thus the number of **larger** elements to the left is $inv[i] = (i - 1) - Query(a[i])$.
- **Step 3: Count larger elements to the right:** Reset the BIT, then scan right to left. The number of smaller elements already seen to the right is `Query(a[i])`. Thus the number of **larger** elements to the right is $(n - i) - Query(a[i])$.
- **Step 4: Compute optimal total:** For each element, the minimum number of moves is the smaller of the two directions. The result is:
  $$Ans = \sum_{i=1}^{n} \min(inv[i], (n - i) - Query(a[i]))$$

### 3. Proof of correctness

- **Greedy strategy:** When considering elements from smallest to largest, the current smallest element can be pushed to the left or right boundary without affecting the relative order of larger elements.
- **Swap count:** When the smallest element moves to a boundary, it only needs to swap with larger elements blocking its path. The cost is therefore the number of larger elements to its left or right, and we choose the cheaper direction.

## Example

Array: `2 1 5 3`.

1. The smallest element is `1`. To its left there is 1 larger element (`2`), to its right there are 2 larger elements (`5, 3`).
2. Push `1` leftward costs 1 swap: `1 2 5 3` (This is already a pyramid array).
3. Result: **1** swap.

## Complexity

- **Time:** $O(n \log n)$ — For coordinate compression sorting and 2 BIT scan passes.
- **Memory:** $O(n)$ — For auxiliary arrays and the BIT.

## Code (C++)

[Solution Code](../code/Pyramid%20Array.cpp)
