# Monotone Subsequences - Solution

**ID:** 2215 | **URL:** https://cses.fi/problemset/task/2215

## Approach

### Problem Restatement

Construct a permutation of $1, 2, \ldots, n$ such that the longest monotone subsequence (increasing or decreasing) has exactly $k$ elements.

### Core idea

By the Erdős–Szekeres theorem, any sequence of more than $(k-1)^2$ distinct numbers contains a monotone subsequence of length $k$, so we need $n \le k^2$. When this holds, divide the permutation into blocks of size $k$, each sorted in decreasing order, with blocks themselves increasing:

$$\underbrace{k, k-1, \ldots, 1}_{\text{Block 1}}, \underbrace{2k, 2k-1, \ldots, k+1}_{\text{Block 2}}, \ldots$$

- **Longest decreasing subsequence:** Since every element of a later block is larger than every element of an earlier block ($ik+1 > (i-1)k$), a decreasing subsequence cannot span two blocks. It is confined to a single block of size $k$, giving length $k$.
- **Longest increasing subsequence:** Within each block, elements decrease, so at most one element can be chosen per block. The number of blocks is $\lceil n/k \rceil \le k$, so the longest increasing subsequence has length $\le k$.

Thus the longest monotone subsequence is $\max(k, \lceil n/k \rceil) = k$ when $\lceil n/k \rceil \le k$ (equivalently $n \le k^2$). Otherwise, output `IMPOSSIBLE`.

### Algorithm

1. If $\lceil n/k \rceil > k$: output `IMPOSSIBLE`.
2. Otherwise, for $i = 1, 2, \ldots, \lceil n/k \rceil$: output $\min(ik, n), \min(ik, n) - 1, \ldots, (i-1)k + 1$.

### Example

Problem examples (input `3` test cases):

- $n = 5, k = 3$: $\lceil 5/3 \rceil = 2 \le 3$. Blocks: `3 2 1 | 5 4`. Longest decreasing: `3 2 1` (length 3). Longest increasing: `1 5` (length 2). Output: `3 2 1 5 4`.
- $n = 5, k = 2$: $\lceil 5/2 \rceil = 3 > 2$. Output: `IMPOSSIBLE`.
- $n = 7, k = 7$: $\lceil 7/7 \rceil = 1 \le 7$. Block: `7 6 5 4 3 2 1`. Longest decreasing: 7. Output: `7 6 5 4 3 2 1` (or `1 2 3 4 5 6 7`).

## Complexity

- **Time:** $O(n)$ per test case
- **Space:** $O(1)$ (excluding output)

## Code (C++)

[Solution Code](../code/Monotone%20Subsequences.cpp)
