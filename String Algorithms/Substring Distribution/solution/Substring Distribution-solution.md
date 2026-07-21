# Substring Distribution - Solution

**ID:** 2110 | **URL:** https://cses.fi/problemset/task/2110

## Problem Statement

Given a string $s$ of length $n$ (characters 'a'–'z'), for each length $k = 1..n$, print the number of distinct substrings of length exactly $k$.

## Approach

### Step 1: Suffix array, LCP, and each suffix's contribution

Every substring is a prefix of some suffix. Sort the suffixes lexicographically (suffix array $sa$), and use $lcp[i] = \text{LCP}(sa[i-1], sa[i])$ to remove duplicates. Suffix $sa[i]$ has $n - sa[i]$ prefixes (substrings); the first $lcp[i]$ of them are shared with the previous suffix, so it contributes only **new** substrings of lengths:

$$[lcp[i]+1, n - sa[i]] \quad (i \ge 1); \qquad [1, n - sa[0]] \quad (i = 0)$$

**Correctness (each distinct substring counted exactly once):** if a substring $w$ occurs at several positions, the corresponding suffixes form a contiguous block in $sa$ all sharing the prefix $w$; the first suffix of the block (smallest in $sa$) is the first to have $w$ as a prefix and contributes length $|w|$, while later suffixes have $lcp \ge |w|$ and do not contribute this length. So $w$ is counted exactly once. (The contribution range is always valid, never empty: a suffix cannot be a prefix of the suffix immediately before it in lexicographic order — if it were, it would be smaller, contradicting the sorted order — so $lcp[i] < n - sa[i]$.)

### Step 2: Difference array and recovering the result

Instead of incrementing each length individually, use a difference array $\text{ans}$ to add 1 to the whole contribution range in $O(1)$:

- $i = 0$: $\text{ans}[1]\mathrel{+}=1$, $\text{ans}[n - sa[0] + 1]\mathrel{-}=1$.
- $i \ge 1$: $\text{ans}[lcp[i]+1]\mathrel{+}=1$, $\text{ans}[n - sa[i] + 1]\mathrel{-}=1$.

After processing all $n$ suffixes, recover the result with a cumulative prefix sum:

$$\text{result}[k] = \sum_{j=1}^{k} \text{ans}[j]$$

### Example

Using the example from the problem statement: $s = \text{"abab"}$ ($n = 4$).

| $i$ | $sa[i]$ | suffix | $n - sa[i]$ | $lcp[i]$ | contribution range |
|---|---|---|---|---|---|
| 0 | 2 | ab | 2 | — | $[1, 2]$ |
| 1 | 0 | abab | 4 | 2 | $[3, 4]$ |
| 2 | 3 | b | 1 | 0 | $[1, 1]$ |
| 3 | 1 | bab | 3 | 1 | $[2, 3]$ |

The contribution ranges correspond to new substrings: `ab` $\to$ {`a`, `ab`}; `abab` $\to$ {`aba`, `abab`} (`ab` shared); `b` $\to$ {`b`}; `bab` $\to$ {`ba`, `bab`} (`b` shared).

Difference array (updated by the ranges above): $\text{ans}[1..5] = [2, 0, 0, -1, -1]$.

Prefix sums: $\text{result}[1..4] = [2, 2, 2, 1]$.

By length: length 1 has $\{$`a`, `b`$\}$ (2); length 2 has $\{$`ab`, `ba`$\}$ (2); length 3 has $\{$`aba`, `bab`$\}$ (2); length 4 has $\{$`abab`$\}$ (1).

Result:
```
2 2 2 1
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ building $sa$ with SA-IS, computing $lcp$ with Kasai, updating the difference array, and the prefix-sum scan are all linear.
- **Memory:** $O(n)$ $\textemdash$ storing the suffix array, the LCP array, and the difference array.

## Code (C++)

[Solution Code](../code/Substring%20Distribution.cpp)
