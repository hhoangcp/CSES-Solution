# Distinct Values Splits - Solution

**ID:** 3190 | **URL:** https://cses.fi/problemset/task/3190

## Problem Statement

Given an array of $n$ integers, count the number of ways to split the array into consecutive segments such that each segment contains only distinct values (no value is repeated within the same segment). Return the result modulo $10^9 + 7$.

## Approach

### 1. Dynamic Programming formulation

Let $dp[i]$ be the number of valid splits for the prefix of the first $i$ elements ($a[1 \dots i]$).

- Base case: $dp[0] = 1$ (there is exactly one way to split an empty array).
- To compute $dp[i]$, we can place the last cut at position $j$ ($0 \le j < i$). The split is valid if:
  1. The prefix $a[1 \dots j]$ is already split validly (there are $dp[j]$ ways).
  2. The last segment $a[j+1 \dots i]$ contains distinct values.
- Formula: $dp[i] = \sum dp[j]$ for all $j$ satisfying the condition that $a[j+1 \dots i]$ consists of distinct values.

### 2. Optimization using Two Pointers

For each ending position $i$, there exists a smallest starting position $L[i]$ such that the segment $a[L[i] \dots i]$ contains distinct values. Then, all valid cut positions $j$ must lie in the range $[L[i]-1, i-1]$.

- Use the two-pointer technique combined with a data structure (such as `std::map` or a marking array) to track the last occurrence of each value.
- When the right pointer $i$ advances and encounters a value already present in the current segment, the left pointer $j$ is pushed past the previous occurrence of that value.

### 3. Range sum optimization using Prefix Sums

Instead of computing the sum of $dp[j]$ via a loop (costing $O(n)$), we use the prefix sum array $pre[i] = \sum_{k=0}^{i} dp[k]$ to compute the sum in $O(1)$.

- Optimized formula: $dp[i] = pre[i-1] - pre[L[i]-2]$.
- Note: If $L[i]-2 < 0$, treat the $pre$ value at that index as $0$.

### Proof of correctness

- **Completeness:** Every valid split ending at $i$ has its last segment $a[j+1 \dots i]$ satisfying the distinctness condition. The range $[L[i], i]$ covers all valid starting positions.
- **Monotonicity:** As $i$ increases, $L[i]$ can only stay the same or increase (shift right), because adding an element can only increase the chance of duplication, never decrease it.

## Example walkthrough

Array: `1 2 1 3`, $n=4$.

| $i$ | $a[i]$ | Longest distinct segment ending at $i$ | Valid $j$ ($j \in [L-1, i-1]$) | $dp[i]$ |
|:---|:---|:---|:---|:---|
| 0 | - | - | - | $dp[0]=1$ |
| 1 | 1 | `[1]` | $j \in [0, 0]$ | $dp[1] = dp[0] = 1$ |
| 2 | 2 | `[1, 2]` | $j \in [0, 1]$ | $dp[2] = dp[0] + dp[1] = 2$ |
| 3 | 1 | `[2, 1]` | $j \in [1, 2]$ | $dp[3] = dp[1] + dp[2] = 3$ |
| 4 | 3 | `[2, 1, 3]` | $j \in [1, 3]$ | $dp[4] = dp[1] + dp[2] + dp[3] = 6$ |

Result: **6** ways.

## Complexity

- **Time:** $O(n \log n)$ with `std::map`, or $O(n)$ with a marking array/`unordered_map`.
- **Memory:** $O(n)$ for the $dp$ array, prefix sum array, and last-occurrence tracking.

## Code (C++)

[Solution Code](../code/Distinct%20Values%20Splits.cpp)
