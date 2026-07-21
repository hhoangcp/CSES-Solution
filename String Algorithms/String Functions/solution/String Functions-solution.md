# String Functions - Solution

**ID:** 2107 | **URL:** https://cses.fi/problemset/task/2107

## Problem Statement

Given a string $s$ of length $n$ (positions $1..n$, characters 'a'–'z'), compute and print two functions:
- $z(i)$: the maximum length of a substring starting at $i$ that is a prefix of $s$; by convention $z(1)=0$.
- $\pi(i)$: the maximum length of a substring ending at $i$ that is a prefix of $s$, with length $\le i-1$ (the longest proper border of $s[1..i]$, i.e. a suffix equal to a prefix).

Print two lines: first the $z$ values, then the $\pi$ values.

## Approach

### Step 1: Z-function

$Z[i] = \max\{k : s[i..i+k-1] = s[1..k]\}$, with $Z[1] = 0$. Maintain the rightmost segment $[L, R]$ matching the prefix ($s[L..R] = s[1..R-L+1]$). For $i$ from $2$ to $n$:

1. **Initialize:** if $i \le R$, exploit symmetry about $L$ (mirror position $i-L+1$): $Z[i] = \min(Z[i-L+1], R-i+1)$ — the known mirror value, capped by the boundary $R$ (positions past $R$ are unchecked). If $i > R$, set $Z[i]=0$.
2. **Extend:** increase $Z[i]$ while $s[i+Z[i]] = s[Z[i]+1]$.
3. **Update:** if $i + Z[i] - 1 > R$, set $L = i$, $R = i + Z[i] - 1$.

### Step 2: Prefix function

$\pi[i] = \max\{k : 1 \le k < i, s[1..k] = s[i-k+1..i]\}$, with $\pi[1] = 0$. For $i$ from $2$ to $n$:

1. Set $j = \pi[i-1]$ (the longest match length at the previous position).
2. While $j > 0$ and $s[i] \neq s[j+1]$, set $j = \pi[j]$.
3. If $s[i] = s[j+1]$, increment $j$.
4. Set $\pi[i] = j$.

**Correctness of the fallback step:** from $j = \pi[i-1]$ we have $s[1..j] = s[i-j..i-1]$. If $s[i] \neq s[j+1]$, the prefix of length $j+1$ does not match; we need a shorter prefix $j' < j$ that is still a suffix of $s[1..i-1]$ and can continue matching $s[i]$. Since every suffix of $s[1..j]$ equal to a prefix is managed by $\pi$, the largest next candidate is exactly $j' = \pi[j]$. Repeat until a match is found or $j = 0$.

### Example

Using the example from the problem statement: $s = \text{"abaabca"}$ ($n = 7$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| $s[i]$ | a | b | a | a | b | c | a |
| $Z[i]$ | 0 | 0 | 1 | 2 | 0 | 0 | 1 |
| $\pi[i]$ | 0 | 0 | 1 | 1 | 2 | 0 | 1 |

Some notable values:
- $Z[4] = 2$: $s[4..5] = \text{"ab"} = s[1..2]$, then stops because $s[6]=\text{c} \neq s[3]=\text{a}$.
- $Z[7] = 1$: $s[7] = \text{"a"} = s[1]$.
- $\pi[5] = 2$: the prefix $\text{"ab"}$ (length 2) is also a suffix of $s[1..5] = \text{"abaab"}$ ($s[4..5]$).
- $\pi[7] = 1$: the prefix $\text{"a"}$ is a suffix of $s[1..7] = \text{"abaabca"}$ ($s[7]$).

Result:
```
0 0 1 2 0 0 1
0 0 1 1 2 0 1
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ for the Z-function, each successful extension increases the right boundary $R$ by at least 1 and $R \le n$; for the prefix function, $j$ increases at most $n$ times (at most 1 per position) and each decrease reduces it by at least 1, so total decreases $\le n$. Both are linear.
- **Memory:** $O(n)$ $\textemdash$ storing the two arrays $Z$ and $\pi$.

## Code (C++)

[Solution Code](../code/String%20Functions.cpp)
