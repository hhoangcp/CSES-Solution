# Minimizing Coins - Solution

**ID:** 1634 | **URL:** https://cses.fi/problemset/task/1634

## Approach

### Problem Restatement

Given $n$ coin types with values $c_1, \ldots, c_n$ and a target sum $x$, find the minimum number of coins to produce sum $x$ (unlimited supply of each coin type). Output $-1$ if impossible.

### Core Idea

Let $dp[i]$ be the minimum number of coins to produce sum $i$ (or $+\infty$ if impossible). Consider the **last coin** added in an optimal solution for sum $i$: if it has value $c_j$, then the remaining $i - c_j$ must also be solved optimally. Taking the minimum over all choices of the last coin:

$$dp[i] = \min_{\substack{j=1,\ldots,n \\ i \ge c_j}} \big(dp[i - c_j] + 1\big)$$

Base case: $dp[0] = 0$. Initialize $dp[i] = +\infty$ for $i \ge 1$.

**Why this is correct (optimal substructure):** If the remainder $i - c_j$ could be produced with fewer coins than $dp[i - c_j]$, replacing it would yield a better solution for $i$ — contradicting optimality. The formula also covers all possibilities since every optimal configuration must end with some coin $c_j$.

### Algorithm

1. Set $dp[0] = 0$, $dp[i] = +\infty$ for $i = 1, \ldots, x$.
2. For $i = 1$ to $x$: compute $dp[i]$ using the recurrence above.
3. Output $dp[x]$ if finite, otherwise $-1$.

### Example

Coins $\{1, 5, 7\}$, $x = 11$:

| $i$ | $dp[i]$ | Best last coin |
|-----|---------|----------------|
| 0 | 0 | — |
| 1 | $dp[0]+1 = 1$ | 1 |
| 5 | $dp[0]+1 = 1$ | 5 |
| 6 | $dp[5]+1 = 2$ | 5 |
| 7 | $dp[0]+1 = 1$ | 7 |
| 10 | $dp[5]+1 = 2$ | 5 |
| 11 | $\min(dp[10]+1, dp[6]+1, dp[4]+1) = 3$ | 5 |

Result: $dp[11] = 3$ (e.g., $5 + 5 + 1$).

## Complexity

- **Time:** $O(n \cdot x)$ — for each sum $1 \ldots x$, iterate $n$ coin types
- **Space:** $O(x)$ — for the $dp$ array

## Code (C++)

[Solution Code](../code/Minimizing%20Coins.cpp)
