# Bit Substrings - Solution

**ID:** 2115 | **URL:** https://cses.fi/problemset/task/2115

## Problem Statement

Given a binary string of length $n$, for each $k$ from $0$ to $n$, count the number of non-empty substrings containing exactly $k$ ones.

## Approach

### Case $k = 0$

Substrings with 0 ones consist entirely of consecutive zeros. A run of $c$ zeros contributes $\binom{c+1}{2}$ substrings. Handle separately.

### Distance array

Let positions of ones be $p_1 < p_2 < \cdots < p_m$. Build array $\text{Num}$ of length $m + 1$:

- $\text{Num}[0]$ = zeros before first one $+ 1$
- $\text{Num}[i]$ ($1 \leq i \leq m-1$) = zeros between $p_i$ and $p_{i+1}$ $+ 1$
- $\text{Num}[m]$ = zeros after last one $+ 1$

A substring from position $a$ to $b$ containing exactly the ones $p_{i+1}, \ldots, p_{i+k}$ has $a$ ranging over $\text{Num}[i]$ choices and $b$ over $\text{Num}[i+k]$ choices. Summing over all valid $i$:

$$\text{count}(k) = \sum_{i=0}^{m-k} \text{Num}[i] \cdot \text{Num}[i+k]$$

This is a convolution of $\text{Num}$ with its reverse — compute via FFT in $O(n \log n)$.

### Example

String `101`: positions of ones: $p_1 = 1, p_2 = 3$. $\text{Num} = [1, 2, 1]$.

| $k$ | Computation | Count |
|-----|-------------|-------|
| 0 | one run of 1 zero: $\binom{2}{2} = 1$ | 1 |
| 1 | $1 \cdot 2 + 2 \cdot 1 = 4$ | 4 |
| 2 | $1 \cdot 1 = 1$ | 1 |

Result: `1 4 1 0`.

## Complexity

- **Time:** $O(n \log n)$ — FFT dominates
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Bit%20Substrings.cpp)
