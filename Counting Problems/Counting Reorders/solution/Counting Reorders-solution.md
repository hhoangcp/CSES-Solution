# Counting Reorders - Solution

**ID:** 2421 | **URL:** https://cses.fi/problemset/task/2421

## Approach

### Problem Restatement

Count the number of rearrangements of a string such that no two adjacent characters are the same. Result modulo $10^9 + 7$.

### DP on groups (runs)

Let $c_1, c_2, \ldots, c_{26}$ be the character frequencies. Define $\text{dp}[i][j]$ = number of ways to arrange the first $i$ character types into exactly $j$ **groups** (runs of consecutive identical characters).

For example, the sequence `AABBC` has 3 groups: `{AA}, {BB}, {C}`.

**Base case:** $\text{dp}[0][0] = 1$ (no characters placed, 0 groups).

**Goal:** An arrangement with no adjacent identical characters has $j = n$ groups (each character forms its own group of size 1).

### Transition

When adding character type $i$ with frequency $\text{num} = c_i$ to an arrangement with $j$ existing groups, split the `num` identical characters into $k$ new groups ($1 \le k \le \text{num}$) and interleave them among the existing groups:

$$\text{dp}[i+1][j+k] \mathrel{+}= \text{dp}[i][j] \cdot \binom{\text{num}-1}{k-1} \cdot \binom{j+k}{k}$$

The two binomial coefficients count:

1. **$\binom{\text{num}-1}{k-1}$**: Split `num` identical items into $k$ non-empty groups (stars-and-bars: place $k-1$ dividers among $\text{num}-1$ internal positions).

2. **$\binom{j+k}{k}$**: Interleave $k$ new groups among $j$ existing groups. Distribute $k$ identical groups into the $j+1$ gaps (before, between, and after existing groups) using stars-and-bars: $\binom{k+j}{k} = \binom{k+j}{j}$.

Multiple new groups placed in the same gap become adjacent, forming a larger run of the same character — this is allowed in the DP and corrected by inclusion-exclusion.

### Inclusion-exclusion

After processing all 26 character types, $\text{dp}[26][j]$ counts arrangements with $j$ groups. An arrangement with $j$ groups has $n - j$ pairs of adjacent same-type characters (each group of size $g$ contributes $g - 1$ such pairs, and $\sum(g-1) = n - j$).

To count only arrangements with **zero** such pairs (i.e., $j = n$), apply inclusion-exclusion. Each arrangement with $n - j$ "violations" contributes $(-1)^{n-j}$ to the signed sum, and by the principle of inclusion-exclusion, only violation-free arrangements survive:

$$\text{ans} = \sum_{j=0}^{n} (-1)^{n-j} \cdot \text{dp}[26][j]$$

### Examples

**Problem example:** string `aabc`, $n = 4$, frequencies $a{=}2, b{=}1, c{=}1$.

**After 'a' (num=2):** Split 2 a's into $k$ groups, placed among 0 existing groups.

| $j$ | $k$ | Formula | $\text{dp}[1][j{+}k]$ |
|-----|-----|---------|----------------------|
| 0 | 1 | $1 \cdot \binom{1}{0} \cdot \binom{1}{1} = 1$ | $\text{dp}[1][1] = 1$ |
| 0 | 2 | $1 \cdot \binom{1}{1} \cdot \binom{2}{2} = 1$ | $\text{dp}[1][2] = 1$ |

**After 'b' (num=1):** Add 1 group of b's.

| From | $k$ | Formula | Contribution |
|------|-----|---------|-------------|
| $j{=}1$ | 1 | $1 \cdot \binom{0}{0} \cdot \binom{2}{1} = 2$ | $\text{dp}[2][2] {+}{=} 2$ |
| $j{=}2$ | 1 | $1 \cdot \binom{0}{0} \cdot \binom{3}{1} = 3$ | $\text{dp}[2][3] {+}{=} 3$ |

**After 'c' (num=1):** Add 1 group of c's.

| From | $k$ | Formula | Contribution |
|------|-----|---------|-------------|
| $j{=}2$ | 1 | $2 \cdot \binom{0}{0} \cdot \binom{3}{1} = 6$ | $\text{dp}[3][3] {+}{=} 6$ |
| $j{=}3$ | 1 | $3 \cdot \binom{0}{0} \cdot \binom{4}{1} = 12$ | $\text{dp}[3][4] {+}{=} 12$ |

Characters d–z have frequency 0, so $\text{dp}[26][3] = 6$, $\text{dp}[26][4] = 12$.

**Inclusion-exclusion:** $\text{ans} = (-1)^{4-3} \cdot 6 + (-1)^{4-4} \cdot 12 = -6 + 12 = \mathbf{6}$. ✓

The 6 valid rearrangements: `abac, abca, acab, acba, baca, caba`.

## Complexity

- **Time:** $O(n^2)$ — for each of 26 character types, $O(n)$ groups $\times$ $O(n)$ split sizes.
- **Space:** $O(n^2)$ — for the DP table and precomputed binomial coefficients.

## Code (C++)

[Solution Code](../code/Counting%20Reorders.cpp)
