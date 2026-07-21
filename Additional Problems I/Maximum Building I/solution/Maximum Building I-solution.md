# Maximum Building I - Solution

**ID:** 1147 | **URL:** https://cses.fi/problemset/task/1147

## Problem Statement

Given a forest map of size $n \times m$ consisting of empty cells (`.`) and tree cells (`*`), find the largest area of a rectangular building that can be placed on empty cells without cutting any trees.

## Approach

### 1. Reduce the 2D problem to 1D

The core idea is to iterate through each row of the grid and treat each row as the "base" of a histogram.

- For each column $j$ at row $i$, compute the height $h[j]$ as the number of consecutive empty cells extending from row $i$ upward.
- Height update formula when transitioning from row $i-1$ to row $i$:
  - If cell $(i, j)$ is a tree (`*`): $h[j] = 0$.
  - If cell $(i, j)$ is empty (`.`): $h[j] = h[j] + 1$.

### 2. Solve the "Largest Rectangle in a Histogram" problem

At each row $i$, after obtaining the height array $h[1 \dots m]$, the problem becomes finding the largest rectangle in this histogram (similar to the **Advertisement** problem).

- Use a **Monotone Stack** to find the left boundary $L[j]$ and right boundary $R[j]$ for each column $j$:
  - $L[j]$ is the nearest position to the left of $j$ where $h[L[j]] < h[j]$.
  - $R[j]$ is the nearest position to the right of $j$ where $h[R[j]] < h[j]$.
- The largest area at row $i$ using column $j$ as the minimum height is:
  $$\text{Area} = h[j] \times (R[j] - L[j] - 1)$$

### 3. Proof of correctness

- **Completeness:** Every empty rectangle in the 2D grid must have some bottom row. When we iterate through all rows from $1$ to $n$, we will certainly examine the row containing the bottom of the optimal rectangle.
- **1D optimality:** At each row, the Monotone Stack algorithm guarantees finding the largest rectangle possible based on the "columns" of empty cells counted from that row upward.

## Example

Sample grid:
```
...*.*.
.*.....
.......
......*
```

- **Row 1:** $h = [1, 1, 1, 0, 1, 0, 1]$. Max area = 3.
- **Row 2:** $h = [2, 0, 2, 1, 2, 1, 2]$ (updated from row 1). Max area = 5.
- **Row 3:** $h = [3, 1, 3, 2, 3, 2, 3]$. Max area = 10.
- **Row 4:** $h = [4, 2, 4, 3, 4, 3, 0]$. Max area = 12.

**Result:** 12.

## Complexity

- **Time:** $O(n \times m)$ — We visit each cell once to update heights and run the monotone stack algorithm ($O(m)$ total per row).
- **Memory:** $O(m)$ — Only the current height array and left/right boundary arrays for one row are needed.

## Code (C++)

[Solution Code](../code/Maximum%20Building%20I.cpp)
