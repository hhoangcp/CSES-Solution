# Xor Pyramid Row - Solution

**ID:** 3195 | **URL:** https://cses.fi/problemset/task/3195

## Approach

### Problem Restatement

Given an XOR pyramid with bottom row $a_0, a_1, \ldots, a_{n-1}$, find all elements on the $k$-th row from the top (the row with $k$ elements).

### Core idea

Going up $d = n - k$ steps from the bottom, the $i$-th element equals $\bigoplus_{j \subseteq d} a_{i+j}$ (by Lucas' theorem: $\binom{d}{j}$ is odd iff $j \subseteq d$). Instead of $d$ sequential steps ($O(nd)$), decompose $d$ into powers of 2 and apply each as a single XOR shift, since going up $2^s$ steps is simply $a'[i] = a[i] \oplus a[i + 2^s]$ (the only submasks of $2^s$ are $\{0, 2^s\}$). These shifts commute over GF(2), so applying them in any order yields the correct result.

### Algorithm

1. Compute $d = n - k$ (number of steps from the bottom row).
2. For each bit $i$ from 0 to 17:
   - If bit $i$ is set in $d$: apply XOR shift at distance $2^i$: $a[j] \mathrel{\oplus}= a[j + 2^i]$ for all valid $j$.
3. Output the first $k$ elements of $a$.

**Why the shifts compose correctly:** Each shift at bit $i$ applies the subset transformation for bit $i$. Since these transformations commute over GF(2), applying the shifts for all set bits of $d$ is equivalent to computing $\bigoplus_{j \subseteq d} a_{i+j}$ for each position $i$.

### Example

Input: $n = 8$, $k = 5$, bottom row $[2, 10, 5, 12, 9, 5, 1, 5]$.

$d = 3 = 11_2$. Submasks of 3: $\{0, 1, 2, 3\}$.

**Bit 0 (shift 1):** $a[j] \oplus= a[j+1]$

| $j$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| Before | 2 | 10 | 5 | 12 | 9 | 5 | 1 | 5 |
| After | 8 | 15 | 9 | 5 | 12 | 4 | 4 | 5 |

**Bit 1 (shift 2):** $a[j] \oplus= a[j+2]$

| $j$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| Before | 8 | 15 | 9 | 5 | 12 |
| After | 1 | 10 | 5 | 1 | 8 |

First 5 elements: `1 10 5 1 8`.

**Verification via formula:** $\text{row}[i] = a_i \oplus a_{i+1} \oplus a_{i+2} \oplus a_{i+3}$ for $d = 3$:
- $2 \oplus 10 \oplus 5 \oplus 12 = 1$, $10 \oplus 5 \oplus 12 \oplus 9 = 10$, $5 \oplus 12 \oplus 9 \oplus 5 = 5$, $12 \oplus 9 \oplus 5 \oplus 1 = 1$, $9 \oplus 5 \oplus 1 \oplus 5 = 8$. $\checkmark$

## Complexity

- **Time:** $O(n \cdot \log n)$ — at most $\log n$ bits, each requiring an $O(n)$ pass
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Xor%20Pyramid%20Row.cpp)
