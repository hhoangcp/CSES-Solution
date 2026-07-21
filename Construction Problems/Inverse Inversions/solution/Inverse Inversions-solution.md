# Inverse Inversions - Solution

**ID:** 2214 | **URL:** https://cses.fi/problemset/task/2214

## Approach

### Problem Restatement

Construct a permutation of $1, 2, \ldots, n$ with exactly $k$ inversions. An inversion is a pair $(a, b)$ where $a < b$ and $p_a > p_b$.

### Core idea

Use two pointers $l = 1$ and $r = n$ to build the permutation left to right. At each position, if the remaining budget $k \ge r - l$, place the largest remaining value $r$ — this creates exactly $r - l$ inversions since all values from $l$ to $r - 1$ will appear after it. Otherwise, place the smallest remaining value $l$, which creates 0 inversions.

This greedy works because each placement of $r$ uses the maximum possible inversions without overshooting: $r - l$ is the exact count of smaller remaining values, and by choosing $r$ whenever affordable, we ensure $k$ is fully consumed. At each step $r - l$ decreases by at least 1 (either $l$ increases or $r$ decreases), so when $l = r$ the budget must be 0 and one value remains.

### Algorithm

1. Initialize $l = 1$, $r = n$.
2. While $l < r$:
   - If $k \ge r - l$: output $r$, set $k \mathrel{-}= r - l$, set $r \mathrel{-}= 1$.
   - Otherwise: output $l$, set $l \mathrel{+}= 1$.
3. Output $l$ (which equals $r$).

### Example

$n = 5$, $k = 4$ (problem example, valid output: `1 5 2 4 3` or `5 1 2 3 4`):

| Step | $l$ | $r$ | $k$ | $r - l$ | Action | Output |
|------|-----|-----|-----|---------|--------|--------|
| 1 | 1 | 5 | 4 | 4 | $k \ge 4$ | 5 |
| 2 | 1 | 4 | 0 | 3 | $k < 3$ | 1 |
| 3 | 2 | 4 | 0 | 2 | $k < 2$ | 2 |
| 4 | 3 | 4 | 0 | 1 | $k < 1$ | 3 |
| 5 | 4 | 4 | 0 | 0 | $l = r$ | 4 |

Result: `5 1 2 3 4` — inversions: $(5,1), (5,2), (5,3), (5,4)$, totaling 4.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(1)$ (excluding output)

## Code (C++)

[Solution Code](../code/Inverse%20Inversions.cpp)
