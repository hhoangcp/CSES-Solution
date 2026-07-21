# Border Subgrid Count I - Solution

**ID:** 3417 | **URL:** https://cses.fi/problemset/task/3417

## Approach

### Problem Restatement

Given an $n \times n$ grid where each cell contains one of the first $k$ uppercase letters, count—for each letter $c$—the number of square subgrids whose entire border consists of letter $c$.

### Border conditions via run-length arrays

A square with top-left $(i, j)$ and size $s$ has all four borders equal to letter $c$ iff:

| Border | Condition | Meaning |
|--------|-----------|---------|
| Top | $R[i][j] \ge s$ | Run of same letter rightward from $(i,j)$ covers the top edge |
| Left | $D[i][j] \ge s$ | Run of same letter downward from $(i,j)$ covers the left edge |
| Bottom | $L[i{+}s{-}1][j{+}s{-}1] \ge s$ | Run of same letter leftward from bottom-right covers the bottom edge |
| Right | $U[i{+}s{-}1][j{+}s{-}1] \ge s$ | Run of same letter upward from bottom-right covers the right edge |

The four arrays $R, D, L, U$ are precomputed in $O(n^2)$ by forward/backward DP scans.

These four conditions are **sufficient**: they implicitly guarantee all borders use the same letter. The top-right corner $(i, j{+}s{-}1)$ must equal $a[i][j]$ (from $R[i][j] \ge s$) and also equal $a[i{+}s{-}1][j{+}s{-}1]$ (from $U[i{+}s{-}1][j{+}s{-}1] \ge s$). Since it's a single cell, $a[i][j] = a[i{+}s{-}1][j{+}s{-}1]$. The same argument applies at the bottom-left corner. Hence all four borders are the same letter.

### Reduction to diagonal processing

Both corners $(i, j)$ and $(i{+}s{-}1, j{+}s{-}1)$ lie on the same diagonal (constant $i - j$). Process each diagonal independently, reducing the 2D problem to 1D.

On a diagonal with positions indexed $0, 1, \ldots, \text{len}-1$:

- $\text{tmp\_u}[k] = \min(R[\text{pos}_k], D[\text{pos}_k])$: maximum square size that can **start** at position $k$ (top-left corner).
- $\text{tmp\_d}[k] = \min(L[\text{pos}_k], U[\text{pos}_k])$: maximum square size that can **end** at position $k$ (bottom-right corner).

We need to count pairs $(p, k)$ with $p \le k$ such that:
- $k - p + 1 \le \text{tmp\_d}[k]$ (bottom/right borders sufficient at $k$)
- $k - p + 1 \le \text{tmp\_u}[p]$ (top/left borders sufficient at $p$)

### Fenwick tree + expiration scheduling

Scan $k$ from left to right. A position $p$ **expires** when the square grows too large for its border capacity: $p$ expires at time $p + \text{tmp\_u}[p]$ (i.e., at the first $k$ where $k - p + 1 > \text{tmp\_u}[p]$).

Use a bucket event system: when processing position $p$, schedule its expiration at time $p + \text{tmp\_u}[p]$. Maintain a **Fenwick tree** (with bitmask acceleration) tracking expired positions. For each $k$:

1. **Process expirations:** Flush all positions scheduled to expire at time $k$, marking them in the Fenwick tree.
2. **Schedule:** Add position $k$ to the expiration bucket at time $k + \text{tmp\_u}[k]$.
3. **Count valid starts:** All positions $p \in [k + 1 - \text{tmp\_d}[k],\ k]$ satisfy the bottom/right condition. Subtract those that have expired. The contribution to $\text{ans}[c_k]$ is:
$$\text{tmp\_d}[k] - \big(\text{total expired} - \text{expired with index} < k + 1 - \text{tmp\_d}[k]\big)$$

The Fenwick tree supports prefix-sum queries in $O(\log n)$, giving $O(n \log n)$ per diagonal and $O(n^2 \log n)$ total.

### Examples

**Problem example:** $n = 5$, $k = 3$, grid:

```
A B B B C
A B A B C
A B B B C
A B B B C
C C C C C
```

**Enumerating all border squares:**

| Letter | Size 1 | Size 2 | Size 3 | Total |
|--------|--------|--------|--------|-------|
| A | 5 cells | — | — | 5 |
| B | 11 cells | (2,1)–(3,2), (2,2)–(3,3) | (0,1)–(2,3) | 14 |
| C | 9 cells | — | — | 9 |

**Tracing diagonal $d = -1$: positions $(0,1)$, $(1,2)$, $(2,3)$, $(3,4)$:**

| $k$ | Cell | Letter | tmp_u | tmp_d | Expirations flushed | Active starts in range | Contribution |
|-----|------|--------|-------|-------|---------------------|----------------------|--------------|
| 0 | (0,1) | B | 3 | 1 | — | {0} | $1 \to$ ans[B] |
| 1 | (1,2) | A | 1 | 1 | — | {1} | $1 \to$ ans[A] |
| 2 | (2,3) | B | 1 | 3 | pos 1 (A) expires | {0, 2} in [0,2] | $2 \to$ ans[B] |
| 3 | (3,4) | C | 1 | 1 | pos 0, 2 expire | {3} in [3,3] | $1 \to$ ans[C] |

At $k = 2$: position 0 (B at $(0,1)$, tmp_u=3) is still active since it expires at time $0+3=3 > 2$. Position 1 (A at $(1,2)$, tmp_u=1) expired at time $1+1=2$. The pair $(p{=}0, k{=}2)$ gives a valid $3 \times 3$ B-bordered square (top-left $(0,1)$, bottom-right $(2,3)$).

**Full result:** Summing over all 9 diagonals: **5, 14, 9**. ✓

## Complexity

- **Time:** $O(n^2 \log n)$ — each of the $O(n)$ diagonals has $O(n)$ positions with $O(\log n)$ Fenwick operations each.
- **Space:** $O(n^2)$ — for the run-length arrays and expiration buckets.

## Code (C++)

[Solution Code](../code/Border%20Subgrid%20Count%20I.cpp)
