# Palindrome Queries - Solution

**ID:** 2420 | **URL:** https://cses.fi/problemset/task/2420

## Problem Statement

Given a string $s$ of $n$ characters (a–z), positions indexed from $1$, process $m$ operations:
1. Change the character at position $k$ to $x$.
2. Ask whether the substring $s[a..b]$ is a palindrome.

## Approach

### Step 1: Polynomial hashing

To check whether $s[l..r]$ is a palindrome, compare its forward hash with its backward hash. Use base $B = 31$ and prime modulo $M = 10^9+8277$; let $v_i = s[i] - \text{'a'} + 1$.

- **Forward hash** (weights decreasing left→right): $H_f(l,r) = \sum_{i=l}^{r} v_i \cdot B^{n-i} \pmod M$.
- **Backward hash** (weights increasing left→right): $H_b(l,r) = \sum_{i=l}^{r} v_i \cdot B^{i-1} \pmod M$.

Since the two hashes use different exponents, normalize before comparing:

$$H_f(l,r) \cdot B^{-(n-r)} \equiv H_b(l,r) \cdot B^{-(l-1)} \pmod M$$

**Correctness:** After normalization, the forward hash becomes $\sum_{i=l}^{r} v_i B^{r-i}$ (coefficients high→low are $v_l, v_{l+1}, \ldots, v_r$), while the backward hash becomes $\sum_{i=l}^{r} v_i B^{i-l}$ (coefficients high→low are $v_r, \ldots, v_l$, i.e. the reversed sequence). The two polynomials are equal iff the sequence $(v_l, \ldots, v_r)$ equals its reverse, i.e. $s[l..r]$ is a palindrome. If it is not a palindrome, the two hashes differ, except in case of a hash collision (probability per query $\approx 1/M$, small enough for $M \approx 10^9$).

### Step 2: Binary Indexed Tree (BIT) for dynamic updates

Because characters must be updated at individual positions, a static prefix-sum array cannot be used. Use two BITs:
- The first BIT stores the forward hash: position $i$ holds $v_i \cdot B^{n-i}$.
- The second BIT stores the backward hash: position $i$ in the original string is mirrored to position $n-i+1$ in this BIT, holding $v_i \cdot B^{i-1}$.

Each BIT supports point updates and prefix-sum queries in $O(\log n)$; the range sum over $[l,r]$ is the difference of two prefix queries. When changing $s[u]$ from old to new, the difference $\Delta = (v_{\text{new}} - v_{\text{old}})$ times the corresponding weight is added to both BITs. To answer a type-2 query on $[l,r]$: obtain $H_f(l,r)$ from the first BIT and $H_b(l,r)$ from the second BIT (using the mirrored indices $n-l+1$ and $n-r$), normalize, and compare.

### Step 3: Precompute powers and inverses

Precompute $B^i \pmod M$ and $B^{-i} \pmod M$ for $i = 0..n$. The inverse is obtained via Fermat's little theorem ($M$ is prime, so $B^{-1} \equiv B^{M-2} \pmod M$, then multiplied cumulatively), bringing the cost of each normalization multiplication down to $O(1)$.

### Example

Using the example from the problem statement: $n=7$, $s = \text{"aybabtu"}$ ($1=\text{a}, 2=\text{y}, 3=\text{b}, 4=\text{a}, 5=\text{b}, 6=\text{t}, 7=\text{u}$), $5$ operations. Let $v(\text{c}) = \text{c}-\text{'a}+1$; the normalized hash of $s[l..r]$ is the polynomial with coefficients $(v_l, \ldots, v_r)$ (forward) and $(v_r, \ldots, v_l)$ (backward).

| # | operation | relevant string | forward hash (normalized) | backward hash (normalized) | result |
|---|---|---|---|---|---|
| 1 | `2 3 5` | $\text{"bab"}$ $(2,1,2)$ | $2B^2 + B + 2$ | $2B^2 + B + 2$ | YES |
| 2 | `1 3 x` | $s \to \text{"ayxabtu"}$ | — | — | (update) |
| 3 | `2 3 5` | $\text{"xab"}$ $(24,1,2)$ | $24B^2 + B + 2$ | $2B^2 + B + 24$ | NO |
| 4 | `1 5 x` | $s \to \text{"ayxaxtu"}$ | — | — | (update) |
| 5 | `2 3 5` | $\text{"xax"}$ $(24,1,24)$ | $24B^2 + B + 24$ | $24B^2 + B + 24$ | YES |

The two normalized hashes match for queries 1 and 5 (palindromes) and differ for query 3 (the $B^2$ coefficient is $24$ vs $2$).

Result:
```
YES
NO
YES
```

## Complexity

- **Time:** $O((n + m) \log n)$ $\textemdash$ BIT initialization $O(n \log n)$; each update or range query on a BIT costs $O(\log n)$.
- **Memory:** $O(n)$ $\textemdash$ two BITs plus the power and inverse arrays.

## Code (C++)

[Solution Code](../code/Palindrome%20Queries.cpp)
