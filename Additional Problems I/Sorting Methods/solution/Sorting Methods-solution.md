# Sorting Methods - Solution

**ID:** 1162 | **URL:** https://cses.fi/problemset/task/1162

## Problem Statement

Given a permutation of $1, 2, \ldots, n$, compute the minimum number of steps to sort it using 4 methods: (1) adjacent swaps, (2) arbitrary swaps, (3) move element to any position, (4) move element to the front.

## Approach

### Method 1: Adjacent swaps → Inversion count

**Minimum steps = Number of inversions.**

Each adjacent swap of $a[i], a[i+1]$ changes the inversion count by exactly $\pm 1$: it decreases by 1 if $a[i] > a[i+1]$ (eliminates that inversion pair), increases by 1 if $a[i] < a[i+1]$ (creates a new inversion). Since a sorted array has 0 inversions, the minimum number of adjacent swaps equals the inversion count.

Compute using BIT: for each element $a[i]$, count the number of previously seen elements with value greater than $a[i]$.

$$\text{inv} = \sum_{i=1}^{n} (i - 1 - \text{Query}(n - a[i]))$$

### Method 2: Swap any two elements → Cycle decomposition

**Minimum steps = $n$ - (number of cycles).**

A permutation decomposes into disjoint cycles. A cycle of length $k$ needs exactly $k - 1$ swaps (swap the element at the first position with the element that belongs there, repeat). Total: $\sum (k_i - 1) = n - c$.

**Optimality:** Each swap increases the number of fixed points (1-cycles) by at most 1, so at least $n - c$ swaps are needed.

### Method 3: Move element to any position → LIS

**Minimum steps = $n$ - (length of LIS).**

Elements in the LIS are in correct relative order and can stay. The remaining $n - |LIS|$ elements each need exactly 1 move.

**Optimality:** Any element not in its final position needs at least 1 move. Since the LIS is the largest set of elements already in correct relative order, at least $n - |LIS|$ moves are needed.

Compute LIS using BIT: for each $a[i]$, $dp[a[i]] = \max_{j < a[i]} dp[j] + 1$.

### Method 4: Move element to the front → Longest suffix subsequence

**Minimum steps = $n$ - (length of longest suffix of $[1..n]$ appearing as a subsequence).**

Find the largest $k$ such that elements $\{k, k+1, \ldots, n\}$ appear in correct left-to-right order. These stay in place; elements $1$ to $k-1$ are moved to the front in reverse order: $k-1, k-2, \ldots, 1$.

**Optimality:** Each move-to-front operation fixes exactly one element at position 1. At least $n - |\text{suffix}|$ such moves are needed.

Scan from right to left: track $ans$ starting from $n$, decrement when $a[i] = ans$.

### Example

Array: `7 8 2 6 5 1 3 4`

| Method | Computation | Result |
| :--- | :--- | :--- |
| **M1** | Count pairs $(i, j)$ where $i < j$ and $a[i] > a[j]$ | **20** |
| **M2** | 2 cycles: $(1 \to 7 \to 3 \to 2 \to 8 \to 4 \to 6)$, $(5)$. Steps: $8 - 2$ | **6** |
| **M3** | LIS = $\{1, 3, 4\}$ or $\{2, 3, 4\}$, length 3. Steps: $8 - 3$ | **5** |
| **M4** | Suffix $\{7, 8\}$ in correct order. Steps: $8 - 2$ | **6** |

Correct output: `20 6 5 6`

## Complexity

- **Time:** $O(n \log n)$ for all 4 methods (BIT in M1 and M3)
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Sorting%20Methods.cpp)
