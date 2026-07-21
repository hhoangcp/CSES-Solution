# Filled Subgrid Count I - Solution

**ID:** 3413 | **URL:** https://cses.fi/problemset/task/3413

## Approach

### Problem Restatement

Given an $n \times n$ grid of uppercase letters, count for each of the first $k$ letters the number of square subgrids where every cell contains the same letter.

### Maximal homogeneous square DP

Define $\text{dp}[i][j]$ = side length of the largest homogeneous square with bottom-right corner at $(i, j)$. For a homogeneous square of size $s$ ending at $(i, j)$, the three overlapping squares of size $s{-}1$ (ending at $(i{-}1, j)$, $(i, j{-}1)$, and $(i{-}1, j{-}1)$) must also be homogeneous. If any is smaller than $s{-}1$, the square at $(i, j)$ cannot reach size $s$. Hence:

$$\text{dp}[i][j] = \begin{cases} \min(\text{dp}[i{-}1][j], \text{dp}[i][j{-}1], \text{dp}[i{-}1][j{-}1]) + 1 & \text{if } a[i][j] = a[i{-}1][j] = a[i][j{-}1] = a[i{-}1][j{-}1] \\ 1 & \text{otherwise} \end{cases}$$

### Counting all homogeneous squares

If $\text{dp}[i][j] = s$, then there are exactly $s$ homogeneous squares ending at $(i, j)$: one each of size $1 \times 1, 2 \times 2, \ldots, s \times s$. Sum $\text{dp}[i][j]$ into the answer for letter $a[i][j]$.

### Example

**Problem example:** $n = 5$, $k = 3$, grid:
```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

DP table:
```
1 1 1 1 1
1 1 2 2 1
1 1 1 1 1
1 1 1 2 2
1 2 2 2 3
```

- **A:** $1 + 1{+}1{+}1 + 1{+}1{+}1{+}2{+}2 + 1{+}2{+}2{+}2{+}3 = 21$
- **B:** $1{+}1{+}1 + 1{+}1{+}2{+}2 + 1 = 10$
- **C:** $1 + 1 + 1 = 3$

Result: 21, 10, 3. ✓

## Complexity

- **Time:** $O(n^2)$ — single pass over the grid.
- **Space:** $O(n^2)$ — for the DP table. Reducible to $O(n)$ by keeping only the current and previous rows.

## Code (C++)

[Solution Code](../code/Filled%20Subgrid%20Count%20I.cpp)
