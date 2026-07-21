# Maximum Subarray Sum II - Solution

**ID:** 1644 | **URL:** https://cses.fi/problemset/task/1644

## Approach

### Problem Restatement

Given an array of $n$ integers, find the maximum sum of a contiguous subarray with length between $a$ and $b$.

### Core Idea

Use prefix sums: $\text{pref}[0] = 0$, $\text{pref}[i] = \sum_{j=1}^{i} x_j$. Subarray $[l, r]$ has sum $\text{pref}[r] - \text{pref}[l-1]$. Let $R = r$, $L = l - 1$; the length constraint becomes $R - b \le L \le R - a$. For each fixed $R$, $\text{pref}[R]$ is constant so we need $\min_{L \in [R-b, R-a]} \text{pref}[L]$ — a range minimum query on a sliding window. Use a segment tree for $O(\log n)$ range-min queries, or a deque (sliding window minimum) for $O(n)$.

### Algorithm (Segment Tree)

1. Build segment tree on $\text{pref}[0..n]$, initialize $\text{pref}[0] = 0$.
2. For $R$ from $1$ to $n$:
   - Update $\text{pref}[R]$ and insert into segment tree.
   - If $R \ge a$: query $\min$ on range $[\max(0, R-b), R-a]$, update $\text{res} = \max(\text{res}, \text{pref}[R] - \text{min\_val})$.
3. Output $\text{res}$.

### Example

Array $[-1, 3, -2, 5, 3, -5, 2, 2]$, $a = 1$, $b = 2$, $n = 8$.

$\text{pref} = [0, -1, 2, 0, 5, 8, 3, 5, 7]$.

| $R$ | $\text{pref}[R]$ | $L$ range | $\min \text{pref}[L]$ | $\text{pref}[R] - \min$ | $\text{res}$ |
|-----|-------------------|-----------|------------------------|--------------------------|--------------|
| 1 | $-1$ | $[0, 0]$ | 0 | $-1$ | $-1$ |
| 2 | $2$ | $[0, 1]$ | $-1$ | $3$ | $3$ |
| 3 | $0$ | $[1, 2]$ | $-1$ | $1$ | $3$ |
| 4 | $5$ | $[2, 3]$ | $0$ | $5$ | $5$ |
| 5 | $8$ | $[3, 4]$ | $0$ | **8** | **8** |
| 6 | $3$ | $[4, 5]$ | $5$ | $-2$ | $8$ |
| 7 | $5$ | $[5, 6]$ | $3$ | $2$ | $8$ |
| 8 | $7$ | $[6, 7]$ | $3$ | $4$ | $8$ |

Result: **8** (subarray $[5, 3]$ at positions 4–5).

## Complexity

- **Time:** $O(n \log n)$ — segment tree; can be optimized to $O(n)$ with deque
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Maximum%20Subarray%20Sum%20II.cpp)
