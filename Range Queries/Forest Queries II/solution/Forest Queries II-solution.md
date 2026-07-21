# Forest Queries II - Solution

**ID:** 1739 | **URL:** https://cses.fi/problemset/task/1739

## Approach

### Problem Restatement

Given an $n \times n$ grid where each cell is empty (`.`) or has a tree (`*`), process $q$ queries:
1. Toggle the state (empty/tree) of cell $(y, x)$.
2. How many trees are inside the rectangle from $(y_1, x_1)$ to $(y_2, x_2)$?

### Core idea

The grid now has point updates, so static 2D prefix sums no longer suffice (each update would require $O(n^2)$ recomputation). We need a dynamic structure supporting both point updates and rectangle sum queries. A **2D Fenwick tree** (2D BIT) achieves both in $O(\log^2 n)$.

A 2D BIT extends the 1D version: each node `bit[i][j]` stores the sum over the rectangle $[i - \text{lowbit}(i) + 1, i] \times [j - \text{lowbit}(j) + 1, j]$, where $\text{lowbit}(x) = x\ \wedge\ (-x)$. Point updates propagate forward along both axes (each axis contributes $O(\log n)$ steps), and prefix sum queries decompose backward along both axes. The query decomposes the rectangle $[1, x] \times [1, y]$ into disjoint sub-rectangles via the standard lowbit descent, and the update distributes a value to all sub-rectangles containing the modified cell. Rectangle queries use inclusion-exclusion with four prefix sums.

### Algorithm

1. **Build:** Read the grid and call `update(i, j, 1)` for each tree cell.
2. **Toggle** (type 1): If the cell currently has a tree, call `update(y, x, -1)` and set state to 0. Otherwise call `update(y, x, +1)` and set state to 1.
3. **Rectangle query** (type 2): Compute
   $$\text{answer} = \text{query}(y_2, x_2) - \text{query}(y_2, x_1{-}1) - \text{query}(y_1{-}1, x_2) + \text{query}(y_1{-}1, x_1{-}1)$$

### Example

Input:
```
4 3
.*..
*.**
**..
****
2 2 2 3 4
1 3 3
2 2 2 3 4
```

Grid:
```
Row 1: . * . .
Row 2: * . * *
Row 3: * * . .
Row 4: * * * *
```

- Query $(2,2)$ to $(3,4)$: $\text{query}(3,4) - \text{query}(3,1) - \text{query}(1,4) + \text{query}(1,1) = 6 - 2 - 1 + 0 = 3$.
- Toggle $(3,3)$: cell was `.` (empty), now becomes `*` (tree). Call `update(3, 3, +1)`.
- Query $(2,2)$ to $(3,4)$: cell $(3,3)$ is now inside and has a tree, so the count increases by 1. Result = 4.

Output:
```
3
4
```

## Complexity

- **Time:** $O(n^2 \log^2 n + q \log^2 n)$
- **Space:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Forest%20Queries%20II.cpp)
