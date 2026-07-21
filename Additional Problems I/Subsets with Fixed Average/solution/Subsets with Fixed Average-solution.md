# Subsets with Fixed Average - Solution

**ID:** 3302 | **URL:** https://cses.fi/problemset/task/3302

## Problem Statement

Count the number of non-empty subsets of an array whose average equals $a$. Result modulo $10^9 + 7$.

## Approach

### Transformation to subset sum

The average of subset $S$ equals $a$ iff:

$$\frac{\sum_{x \in S} x}{|S|} = a \iff \sum_{x \in S} (x - a) = 0$$

Set $b_i = x_i - a$. The problem reduces to: count non-empty subsets of $b$ with sum equal to 0. The mapping $S \mapsto \{x - a : x \in S\}$ is a bijection, so the count is preserved.

### Knapsack DP

Use $dp[s]$ = number of subsets with sum $s$ (shifted by OFFSET to handle negative sums). $\text{OFFSET} = n \times 500 = 250000$, so all feasible sums $s \in [-\text{OFFSET}, \text{OFFSET}]$ map to valid indices.

For each $b_i$:
- If $b_i \geq 0$: iterate $s$ from high to low (0/1 knapsack — avoids double-counting).
- If $b_i < 0$: iterate $s$ from low to high.

$$dp[s + b_i] \mathrel{+}= dp[s]$$

Result: $dp[\text{OFFSET}] - 1$ (subtract the empty set).

### Example

$n = 5, a = 2$, $x = [1, 1, 2, 3, 4]$, $b = [-1, -1, 0, 1, 2]$.

Subsets of $b$ with sum 0 (using original $x$ values for clarity):

| # | Elements from $b$ | Sum | Corresponding $x$ values |
|---|--------------------|-----|--------------------------|
| 1 | $\{0\}$ | 0 | $\{2\}$ |
| 2 | $\{-1, 1\}$ | 0 | $\{1, 3\}$ |
| 3 | $\{-1, 1\}$ | 0 | $\{1, 3\}$ (other 1) |
| 4 | $\{-1, 0, 1\}$ | 0 | $\{1, 2, 3\}$ |
| 5 | $\{-1, 0, 1\}$ | 0 | $\{1, 2, 3\}$ (other 1) |
| 6 | $\{-1, -1, 2\}$ | 0 | $\{1, 1, 4\}$ |
| 7 | $\{-1, -1, 0, 2\}$ | 0 | $\{1, 1, 2, 4\}$ |

Answer: **7**.

## Complexity

- **Time:** $O(n \cdot n \cdot \max(x_i))$ — $500 \times 500000 \approx 2.5 \times 10^8$ simple additions, runs within 1 second
- **Memory:** $O(n \cdot \max(x_i))$ — the $dp$ array of size $500000$

## Code (C++)

[Solution Code](../code/Subsets%20with%20Fixed%20Average.cpp)
