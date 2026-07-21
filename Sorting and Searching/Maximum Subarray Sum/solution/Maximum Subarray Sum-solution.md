# Maximum Subarray Sum - Solution

**ID:** 1643 | **URL:** https://cses.fi/problemset/task/1643

## Approach

### Problem Restatement

Given an array of $n$ integers (possibly negative), find the maximum sum of a non-empty contiguous subarray.

### Core Idea

Define prefix sum $P_0 = 0$, $P_i = x_1 + \cdots + x_i$. Subarray $[a, b]$ has sum $P_b - P_{a-1}$. To maximize this at each $b$, we need the minimum $P_{a-1}$ among positions before $b$. Maintain $h = \min_{0 \le j < i} P_j$ and $S = P_i$; at each step update $\text{res} = \max(\text{res}, S - h)$. This is correct because: for the optimal subarray $[a, b]$, at step $i = b$ we have $h \le P_{a-1}$ so $S - h \ge P_b - P_{a-1} = \text{answer}$, meaning $\text{res} \ge \text{answer}$; conversely $\text{res}$ is always the sum of a valid subarray so $\text{res} \le \text{answer}$. Hence $\text{res} = \text{answer}$. Initialize $h = 0$ (empty prefix $P_0$, allowing subarrays starting at $x_1$) and $\text{res} = -\infty$ (answer can be negative).

### Algorithm

1. Initialize $S = 0$, $h = 0$, $\text{res} = -\infty$.
2. For $i$ from $1$ to $n$:
   - $S \mathrel{+}= x_i$.
   - $\text{res} = \max(\text{res}, S - h)$.
   - $h = \min(h, S)$.
3. Output $\text{res}$.

### Example

Array $[-1, 3, -2, 5, 3, -5, 2, 2]$, $n = 8$.

| $i$ | $x_i$ | $S$ | $h$ (before) | $S - h$ | $\text{res}$ | $h$ (after) |
|-----|-------|-----|-------------|---------|--------------|-------------|
| 1 | $-1$ | $-1$ | 0 | $-1$ | $-1$ | $-1$ |
| 2 | $3$ | $2$ | $-1$ | $3$ | $3$ | $-1$ |
| 3 | $-2$ | $0$ | $-1$ | $1$ | $3$ | $-1$ |
| 4 | $5$ | $5$ | $-1$ | $6$ | $6$ | $-1$ |
| 5 | $3$ | $8$ | $-1$ | $9$ | **9** | $-1$ |
| 6 | $-5$ | $3$ | $-1$ | $4$ | $9$ | $-1$ |
| 7 | $2$ | $5$ | $-1$ | $6$ | $9$ | $-1$ |
| 8 | $2$ | $7$ | $-1$ | $8$ | $9$ | $-1$ |

Optimal subarray: $[3, -2, 5, 3]$ (positions 2–5), sum = **9**.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Maximum%20Subarray%20Sum.cpp)
