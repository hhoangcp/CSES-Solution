# Forest Queries - Solution

**ID:** 1652 | **URL:** https://cses.fi/problemset/task/1652

## Approach

### Problem Restatement

Given an $n \times n$ grid where each cell is empty (`.`) or has a tree (`*`), process $q$ queries: how many trees are inside the rectangle from $(y_1, x_1)$ to $(y_2, x_2)$?

### Core idea

The grid is static (no updates), so **2D prefix sums** allow each query in $O(1)$ with $O(n^2)$ preprocessing.

Define $a[i][j]$ = number of trees in the rectangle from $(1,1)$ to $(i,j)$. Build it using inclusion-exclusion:

$$a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + \text{tree}(i,j)$$

where $\text{tree}(i,j) = 1$ if there's a tree at $(i,j)$, otherwise $0$. The formula is correct by inclusion-exclusion: the rectangles $[1,i{-}1] \times [1,j]$ and $[1,i] \times [1,j{-}1]$ cover $[1,i] \times [1,j]$ except that their intersection $[1,i{-}1] \times [1,j{-}1]$ is counted twice, so we subtract it once and add the cell $(i,j)$.

To answer a query on rectangle $(y_1, x_1)$ to $(y_2, x_2)$:

$$\text{answer} = a[y_2][x_2] - a[y_2][x_1-1] - a[y_1-1][x_2] + a[y_1-1][x_1-1]$$

This applies the same inclusion-exclusion principle: start with $[1,y_2] \times [1,x_2]$, subtract the strips outside the query rectangle, and add back the corner that was subtracted twice.

### Algorithm

1. **Build prefix sum:** Read the grid row by row. For each cell $(i,j)$, compute $a[i][j]$ using the DP formula above.
2. **Answer queries:** For each query, apply the inclusion-exclusion formula in $O(1)$.

### Example

Input:
```
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
```

Grid ($1$-indexed):
```
Row 1: . * . .
Row 2: * . * *
Row 3: * * . .
Row 4: * * * *
```

Prefix sum $a$:
| | j=1 | j=2 | j=3 | j=4 |
|---|---|---|---|---|
| i=1 | 0 | 1 | 1 | 1 |
| i=2 | 1 | 2 | 3 | 4 |
| i=3 | 2 | 4 | 5 | 6 |
| i=4 | 3 | 6 | 8 | 10 |

- Query $(2,2)$ to $(3,4)$: $a[3][4] - a[3][1] - a[1][4] + a[1][1] = 6 - 2 - 1 + 0 = 3$.
- Query $(3,1)$ to $(3,1)$: $a[3][1] - a[3][0] - a[2][1] + a[2][0] = 2 - 0 - 1 + 0 = 1$.
- Query $(1,1)$ to $(2,2)$: $a[2][2] - a[2][0] - a[0][2] + a[0][0] = 2 - 0 - 0 + 0 = 2$.

Output:
```
3
1
2
```

## Complexity

- **Time:** $O(n^2 + q)$
- **Space:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Forest%20Queries.cpp)
