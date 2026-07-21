# Longest Palindrome - Solution

**ID:** 1111 | **URL:** https://cses.fi/problemset/task/1111

## Problem Statement

Given a string $s$ of length $n$ consisting of characters 'a'–'z', find the longest palindromic substring of $s$. If there are several solutions, you may print any of them.

## Approach

### Step 1: String transformation for uniform handling

A palindrome can be odd-length (e.g. $\text{"aba"}$) or even-length (e.g. $\text{"abba"}$). To handle both uniformly, insert a sentinel `#` between every pair of adjacent characters and at both ends, producing $t$ of length $2n+1$. Then every palindrome of $s$ — odd or even — becomes an odd-length palindrome in $t$ (centered at a real character for odd palindromes, or at a `#` for even palindromes).

### Step 2: Manacher's algorithm

For each position $i$ in $t$, compute $M[i]$ = the radius of the longest palindrome centered at $i$, i.e. $t[i-M[i]..i+M[i]]$ is a palindrome and $M[i]$ is the largest such value.

The algorithm maintains the rightmost palindrome window $[L, R]$ ($L$ the center, $R = L + M[L]$). For each position $i$:

1. **Initialize:** If $i \le R$, exploit mirror symmetry about center $L$ (the mirror of $i$ is $2L - i$). The radius at $i$ is at least $\min(R - i, M[2L-i])$: the known mirror value $M[2L-i]$, capped by the right boundary $R - i$ (nothing past $R$ has been checked). Set $M[i] = \min(R - i, M[2L-i])$. If $i > R$, set $M[i] = 0$.
2. **Extend:** Increase $M[i]$ while $t[i-M[i]-1] = t[i+M[i]+1]$ (compare the pair just outside the current boundary), until they differ or the string ends.
3. **Update:** If $i + M[i] > R$, move the window to the new center $L = i$, $R = i + M[i]$.

**Correctness of the mirror initialization:** since $t[2L-R..R]$ is symmetric about $L$, every mirrored pair of characters in this segment is equal; so the palindrome at mirror $2L-i$ (radius $M[2L-i]$) has a mirror image at $i$ of the same radius, capped only by the right boundary $R$. The $\min(R-i, M[2L-i])$ seed is a correct lower bound; the rest is verified by direct extension.

Scanning left to right and updating the answer only when $M[i]$ is strictly greater keeps the first center attaining the maximum radius — i.e. the earliest-appearing palindrome.

### Step 3: Extracting the result

Let $\text{res} = M[c]$ be the maximum radius and $c$ the corresponding center. The longest palindrome length in $s$ equals $\text{res}$ (the number of real characters in the symmetric segment). The result is extracted from $t[c-\text{res}+1..c+\text{res}-1]$, taking only the real characters (even indices), skipping the `#` markers at the two ends.

### Example

Using the example from the problem statement: $s = \text{"aybabtu"}$ ($n = 7$), transformed $t = \text{"\#a\#y\#b\#a\#b\#t\#u\#"}$ ($|t| = 15$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| $t[i]$ | # | a | # | y | # | b | # | a | # | b | # | t | # | u | # |
| $M[i]$ | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 3 | 0 | 1 | 0 | 1 | 0 | 1 | 0 |

The maximum radius is $\text{res} = 3$ at center $c = 8$ (character $\text{a}$). The palindrome in $t$ is $t[5..11] = \text{"\#b\#a\#b\#"}$; extracting the real characters at even indices (6, 8, 10) gives $\text{"bab"}$, of length $3 = \text{res}$.

Result:
```
bab
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ each successful extension increases the right boundary $R$ by at least 1; $R$ only grows from 0 to at most $2n+1$, so the total number of extensions is $O(n)$.
- **Memory:** $O(n)$ $\textemdash$ storing the $M$ array and the transformed string $t$.

## Code (C++)

[Solution Code](../code/Longest%20Palindrome.cpp)
