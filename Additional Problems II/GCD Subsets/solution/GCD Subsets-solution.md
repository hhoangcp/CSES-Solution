# GCD Subsets - Solution

**ID:** 3161 | **URL:** https://cses.fi/problemset/task/3161

## Problem Statement

Given an array of $n$ integers, each $x_i \leq n$. For each $k$ from 1 to $n$, compute the number of non-empty subsets with GCD exactly equal to $k$.

## Approach

### $f(k)$: Subsets with GCD divisible by $k$

Let $c_k$ be the number of elements divisible by $k$. Every non-empty subset consisting solely of elements divisible by $k$ has GCD divisible by $k$, and conversely. The count is $f(k) = 2^{c_k} - 1$.

### $g(k)$: Reverse inclusion-exclusion (Möbius inversion)

Let $g(k)$ be the number of subsets with GCD **exactly** $k$. By definition, $f(k) = \sum_{j: k|j} g(j)$ since every subset with GCD exactly $j$ (where $k | j$) is counted in $f(k)$.

Process $k$ from $n$ down to 1. When computing $g(k)$, all $g(j)$ with $j > k$ are already known, so:

$$g(k) = f(k) - \sum_{j=2k, 3k, \ldots} g(j)$$

## Algorithm

1. Count frequencies: $\text{freq}[v]$ = count of value $v$.
2. Precompute $\text{pow2}[i] = 2^i \bmod (10^9{+}7)$.
3. For $k$ from $n$ down to 1:
   - $c_k = \sum_{j=k, 2k, \ldots} \text{freq}[j]$.
   - $f(k) = \text{pow2}[c_k] - 1$.
   - $g(k) = f(k) - \sum_{j=2k, 3k, \ldots} g(j)$.
4. Output $g(1), g(2), \ldots, g(n)$.

## Example

Array: $[5, 4, 4, 2, 3]$.

| $k$ | $c_k$ | $f(k)$ | subtract | $g(k)$ |
|:---:|:-----:|:------:|:--------:|:------:|
| 5 | 1 | $2^1-1=1$ | — | **1** |
| 4 | 2 | $2^2-1=3$ | — | **3** |
| 3 | 1 | $2^1-1=1$ | — | **1** |
| 2 | 3 | $2^3-1=7$ | $g(4)=3$ | **4** |
| 1 | 5 | $2^5-1=31$ | $g(2)+g(3)+g(4)+g(5)=9$ | **22** |

Result: `22 4 1 3 1`

## Complexity

- **Time:** $O(n \log n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/GCD%20Subsets.cpp)
