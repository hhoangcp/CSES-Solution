# Permutation Subsequence - Solution

**ID:** 3404 | **URL:** https://cses.fi/problemset/task/3404

## Problem Statement

Given two arrays $a$ (of size $n$) and $b$ (of size $m$) that are both permutations, find the longest common subsequence (LCS) of them and print one such subsequence.

## Approach

### 1. Reduce LCS to LIS

The standard LCS problem has complexity $O(N \cdot M)$, which is too slow for $N, M = 2 \cdot 10^5$. However, since both arrays are **permutations**, each value appears exactly once.

- **Step 1:** Build a position array `pos[v]` storing the position of value $v$ in array $b$.
- **Step 2:** Traverse array $a$, and for each element $a[i]$ that exists in $b$, record its position: $c[k] = pos[a[i]]$.
- **Step 3:** A common subsequence of $a$ and $b$ corresponds to an **Increasing Subsequence** of the sequence $c$. Therefore, the LCS of $a$ and $b$ is exactly the **Longest Increasing Subsequence (LIS)** of $c$.

### 2. Find LIS using Fenwick Tree (BIT)

We use a Fenwick Tree to optimize finding the LIS in $O(N \log M)$:

- The Fenwick Tree stores values $\{max\_length, index\}$.
- When processing element $c[i]$, query the BIT to find the maximum LIS length ending with a value smaller than $c[i]$.
- Update the new length $dp[i] = max\_length + 1$ and store the predecessor $pre[i] = index$ for reconstruction.

### 3. Reconstruct the subsequence

After finding the maximum LIS length, start from the position with the largest $dp$ value and use the $pre$ array to trace back the chosen elements. Finally, reverse the result to obtain the correct order.

## Example walkthrough

$a = [3, 1, 2, 8, 5, 7, 6, 4]$, $b = [6, 5, 1, 2, 3, 4]$.

1. Positions in $b$: $6 \to 1, 5 \to 2, 1 \to 3, 2 \to 4, 3 \to 5, 4 \to 6$.
2. Array $c$ (positions of $a[i]$ in $b$): $[5, 3, 4, \dots, 2, \dots, 1, 6]$ (excluding elements not in $b$: 8, 7).
3. LIS of $c$: $[3, 4, 6]$ (length 3).
4. Corresponding values: $b[3]=1, b[4]=2, b[6]=4 \to$ Subsequence: `1 2 4`.

## Complexity

- **Time:** $O((n+m) \log m)$ — For building the position array and BIT queries.
- **Memory:** $O(n+m)$ — Storing arrays $a, b, c, pos, dp$, and $pre$.

## Code (C++)

[Solution Code](../code/Permutation%20Subsequence.cpp)
