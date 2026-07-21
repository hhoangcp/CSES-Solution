# Ferris Wheel - Solution

**ID:** 1090 | **URL:** https://cses.fi/problemset/task/1090

## Approach

### Problem Restatement

There are $n$ children, child $i$ has weight $p_i$. Each gondola holds at most 2 children with total weight $\le x$. Find the minimum number of gondolas.

### Core Idea

Sort weights in increasing order and use two pointers from both ends. The lightest child always needs a gondola; we try to pair them with the heaviest possible child to save gondolas. If $p_i + p_j \le x$, pair them; if $p_i + p_j > x$, the heaviest child cannot pair with anyone (since they're heavier than all others left) and must ride alone. This greedy is optimal: if in an optimal solution the lightest child $i$ rides with some child $k$ lighter than the heaviest available $j$, we can swap — pair $i$ with $j$ (still valid since $p_i + p_k \le x$ implies $p_i \le p_k$) and free the lighter child $k$ who is easier to pair with others, without increasing the gondola count.

### Algorithm

1. Sort array $p$ in increasing order.
2. Initialize $i = 1$, $j = n$, $\text{res} = 0$.
3. While $i \le j$:
   - Increment `res` (gondola for child $i$).
   - If $p_i + p_j \le x$: pair them, increment $i$, decrement $j$.
   - Otherwise: child $j$ rides alone, decrement $j$.

### Example

$n = 4$, $x = 10$, $p = [7, 2, 3, 9]$.

After sorting: $[2, 3, 7, 9]$.

| Step | $i$ | $j$ | $p_i$ | $p_j$ | $p_i + p_j$ | Action | Gondola | res |
|------|-----|-----|-------|-------|-------------|--------|---------|-----|
| 1 | 1 | 4 | 2 | 9 | 11 > 10 | $j$ rides alone | $\{9\}$ | 1 |
| 2 | 1 | 3 | 2 | 7 | 9 ≤ 10 | Pair | $\{2, 7\}$ | 2 |
| 3 | 2 | 2 | 3 | 3 | — | $i = j$, rides alone | $\{3\}$ | 3 |

Result: **3** gondolas.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Ferris%20Wheel.cpp)
