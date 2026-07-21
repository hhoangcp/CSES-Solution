# Book Shop - Solution

**ID:** 1158 | **URL:** https://cses.fi/problemset/task/1158

## Approach

### Problem Restatement

Given $n$ books with prices $h_i$ and pages $s_i$, and a budget $x$, choose a subset of books (each at most once) to maximize total pages without exceeding the budget.

### Core idea

This is the classic **0/1 Knapsack** problem: choose a subset of $n$ items, each with weight $h_i$ and value $s_i$, to maximize total value under a weight capacity $x$. Each item is used at most once.

Let $dp[j]$ be the maximum total pages achievable with total price **at most** $j$. The recurrence for each book $i$ is:

$$dp[j] = \max(dp[j], dp[j - h_i] + s_i) \quad \text{for } j = x, x-1, \ldots, h_i$$

The key insight is iterating $j$ backward. If we iterate forward, $dp[j - h_i]$ may already include book $i$ (updated earlier in the same round), causing book $i$ to be counted twice — this would solve the unbounded knapsack instead. Backward iteration guarantees $dp[j - h_i]$ still reflects only books $1, \ldots, i-1$, so each book is selected at most once. This also ensures optimal substructure: if an optimal solution for budget $j$ includes book $i$, then the remainder must be optimal for budget $j - h_i$; otherwise replacing it with a better sub-solution would improve the whole, contradicting optimality.

### Algorithm

1. Initialize $dp[0 \ldots x] = 0$.
2. For each book $i$ from $1$ to $n$, read price $h_i$ and pages $s_i$:
   - For $j = x$ down to $h_i$: $dp[j] = \max(dp[j], dp[j - h_i] + s_i)$.
3. Answer is $dp[x]$.

### Example

Input: $n = 4$, $x = 10$, prices $= \{4, 8, 5, 3\}$, pages $= \{5, 12, 8, 1\}$.

| After book | $dp[0]$ | $dp[1\textendash 2]$ | $dp[3]$ | $dp[4]$ | $dp[5]$ | $dp[6\textendash 7]$ | $dp[8]$ | $dp[9\textendash 10]$ |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 (4, 5) | 0 | 0 | 0 | 5 | 5 | 5 | 5 | 5 |
| 2 (8, 12) | 0 | 0 | 0 | 5 | 5 | 5 | 12 | 12 |
| 3 (5, 8) | 0 | 0 | 0 | 5 | 8 | 8 | 12 | 13 |
| 4 (3, 1) | 0 | 0 | 1 | 5 | 8 | 8 | 12 | 13 |

Result: $dp[10] = 13$ — buy books 1 and 3 (price $4 + 5 = 9$, pages $5 + 8 = 13$).

## Complexity

- **Time:** $O(n \cdot x)$
- **Space:** $O(x)$

## Code (C++)

[Solution Code](../code/Book%20Shop.cpp)
