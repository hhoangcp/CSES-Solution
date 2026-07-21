# All Letter Subgrid Count II - Solution

**ID:** 3416 | **URL:** https://cses.fi/problemset/task/3416

## Approach

### Problem Restatement

Given an $n \times n$ grid where each cell contains one of the first $k$ uppercase letters, count the number of sub-**rectangles** (not just squares) containing all $k$ letters.

### 2D sparse table for bitmask OR queries

Since $k \le 26$, encode the set of letters in a region as a 32-bit bitmask. A region contains all $k$ letters iff its OR-mask $= (1 \ll k) - 1$. The key property is that OR is **overlap-friendly**: the OR of overlapping regions equals the OR of their union, so we can use a sparse table (unlike min/max where overlaps cause issues with sum or other operations).

Build `st[k1][i][k2][j]` = OR-mask of the $2^{k_1} \times 2^{k_2}$ rectangle starting at $(i, j)$. Construction uses standard doubling in both dimensions in $O(n^2 \log^2 n)$:

- First, extend each row horizontally: `st[0][i][l][j] = st[0][i][l-1][j] | st[0][i][l-1][j + 2^{l-1}]`.
- Then extend vertically: `st[t][i][l][j] = st[t-1][i][l][j] | st[t-1][i + 2^{t-1}][l][j]`.

**Query** rectangle $(x_1, y_1)$ to $(x_2, y_2)$ in $O(1)$: let $lx = \lfloor\log_2(x_2 - x_1 + 1)\rfloor$, $ly = \lfloor\log_2(y_2 - y_1 + 1)\rfloor$. Four overlapping power-of-2 rectangles cover the target:

$$\text{result} = st[lx][x_1][ly][y_1] \mid st[lx][x_2{-}2^{lx}{+}1][ly][y_1] \mid st[lx][x_1][ly][y_2{-}2^{ly}{+}1] \mid st[lx][x_2{-}2^{lx}{+}1][ly][y_2{-}2^{ly}{+}1]$$

Since OR is idempotent (overlapping regions don't cause overcounting), this gives the exact mask of the target rectangle.

### Two pointers on columns

For each row pair $(l, r)$ (there are $O(n^2)$ such pairs), count the number of column pairs $(j, i)$ with $j \le i$ such that rectangle rows $[l, r]$, columns $[j, i]$ contains all $k$ letters.

**Monotonicity:** If the rectangle $(l, j, r, i)$ contains all letters, then widening it (decreasing $j$ or increasing $i$) preserves this property — we only add cells, which can only add letters via set union. Equivalently, for a fixed right boundary $i$, if we increase $j$ (narrow the rectangle) and lose a required letter, further increasing $j$ cannot recover it. So the leftmost valid $j$ is non-decreasing as $i$ increases.

**Algorithm:** Maintain pointer $j$ (the smallest column such that the rectangle does **not** yet contain all letters; valid left boundaries are $1, \ldots, j-1$). For each $i$ from 1 to $n$:

```
while j ≤ i and rectangle(l, j, r, i) contains all letters:
    j++
contribution = j - 1
```

The pointer $j$ only moves forward across all $i$, so each row pair costs $O(n)$ amortized, plus $O(n)$ sparse-table queries.

### Examples

**Problem example:** $n = 5$, $k = 3$, grid:

```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

**Row pair $(1, 3)$ (1-indexed):**

| $i$ | $j$ (after loop) | Rectangles checked | Contribution ($j-1$) |
|-----|-------------------|-------------------|----------------------|
| 1 | 1 | $(1,1,3,1)$: $\{A,B\} \ne$ full | 0 |
| 2 | 2 | $(1,1,3,2)$: $\{A,B,C\}$ = full → $j$++ ; $(1,2,3,2)$: $\{B,C\} \ne$ full → stop | 1 |
| 3 | 3 | $(1,2,3,3)$: $\{A,B,C\}$ = full → $j$++ ; $(1,3,3,3)$: $\{A,B\} \ne$ full → stop | 2 |
| 4 | 3 | $(1,3,3,4)$: $\{A,B\} \ne$ full → stop | 2 |
| 5 | 5 | $(1,3,3,5)$: $\{A,B,C\}$ = full → $j$++ ; $(1,4,3,5)$: $\{A,B,C\}$ = full → $j$++ ; $(1,5,3,5)$: $\{A,C\} \ne$ full → stop | 4 |

Subtotal for this row pair: $0 + 1 + 2 + 2 + 4 = 9$.

**Summing over all 15 row pairs** $(l, r)$ with $l \le r$ gives **70**. ✓

## Complexity

- **Time:** $O(n^2 \log^2 n + n^3)$ — $O(n^2 \log^2 n)$ to build the sparse table, $O(n^3)$ for all row pairs with two pointers.
- **Space:** $O(n^2 \log^2 n)$ — for the 2D sparse table.

## Code (C++)

[Solution Code](../code/All%20Letter%20Subgrid%20Count%20II.cpp)
