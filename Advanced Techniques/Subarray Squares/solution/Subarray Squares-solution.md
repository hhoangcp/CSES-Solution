# Subarray Squares - Solution

**ID:** 2086 | **URL:** https://cses.fi/problemset/task/2086

## Approach

### Problem Restatement

Given an array of $n$ elements, partition it into $k$ contiguous subarrays. The cost of each subarray is the square of the sum of its elements. Minimize the total cost.

### Core Idea

Define $dp[j][i]$ = minimum cost to partition the first $j$ elements into $i$ subarrays. Let $S_j$ be the prefix sum. The recurrence is:

$$dp[j][i] = \min_{k < j} \left( dp[k][i-1] + (S_j - S_k)^2 \right)$$

Expanding the square and separating terms involving $S_j$:

$$dp[j][i] = S_j^2 + \min_{k < j} \left( -2S_k \cdot S_j + (dp[k][i-1] + S_k^2) \right)$$

This is a linear function $y = mx + b$ in $x = S_j$ with slope $m = -2S_k$ and intercept $b = dp[k][i-1] + S_k^2$. Since prefix sums are non-decreasing, slopes are inserted in non-increasing order and queries $x = S_j$ are non-decreasing. This enables **Convex Hull Trick (CHT)** with a deque: maintain the lower hull, pop front when a better line exists (safe because queries only move right), and pop back when the new line makes the last line redundant (checked via cross-product intersection test).

Naive DP is $O(k \cdot n^2)$; CHT reduces each layer to $O(n)$ amortized.

### Algorithm

1. Compute prefix sums. Initialize $dp[j][1] = S_j^2$.
2. For $i = 2$ to $k$:
   - Clear the CHT deque.
   - Insert line for $k = i{-}1$: slope $-2S_{i-1}$, intercept $dp[i{-}1][i{-}1] + S_{i-1}^2$.
   - For $j = i$ to $n$:
     - Query CHT at $x = S_j$: $dp[j][i] = \text{Query}(S_j) + S_j^2$.
     - Insert line: slope $-2S_j$, intercept $dp[j][i{-}1] + S_j^2$.
3. Output $dp[n][k]$.

### Example

$n=8$, $k=3$, array: $[2, 3, 1, 2, 2, 3, 4, 1]$.

Prefix sums: $S = [0, 2, 5, 6, 8, 10, 13, 17, 18]$.

Optimal partition: $[2,3,1]$, $[2,2,3]$, $[4,1]$.

| Subarray | Sum | Cost |
|----------|-----|------|
| $[2,3,1]$ | 6 | $6^2 = 36$ |
| $[2,2,3]$ | 7 | $7^2 = 49$ |
| $[4,1]$ | 5 | $5^2 = 25$ |

Total: $36 + 49 + 25 = \mathbf{110}$.

## Complexity

- **Time:** $O(k \cdot n)$
- **Memory:** $O(n \cdot k)$

## Code (C++)

[Solution Code](../code/Subarray%20Squares.cpp)
