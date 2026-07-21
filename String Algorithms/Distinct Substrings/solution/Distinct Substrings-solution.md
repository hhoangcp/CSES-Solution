# Distinct Substrings - Solution

**ID:** 2105 | **URL:** https://cses.fi/problemset/task/2105

## Problem Statement

Given a string $s$ of length $n$ consisting of characters 'a'–'z', count the number of distinct substrings of $s$.

## Approach

### Step 1: Core idea

Every substring of $s$ is a prefix of some suffix. Listing all prefixes of all suffixes, the total (with duplicates) is:

$$\text{Total} = \sum_{i=0}^{n-1} (n - sa[i]) = \frac{n(n+1)}{2}$$

where $sa$ is the suffix array (starting indices of suffixes in lexicographic order). To remove duplicates we must know how many prefixes each suffix shares with the suffixes before it — exactly what the LCP array provides.

### Step 2: Deduplicating with the LCP array

The LCP array stores the longest common prefix length of two adjacent suffixes in the sorted suffix array: $lcp[i] = \text{LCP}(sa[i-1], sa[i])$.

For suffix $sa[i]$, it has $n - sa[i]$ prefixes. Of these, the first $lcp[i]$ already overlap with the predecessor $sa[i-1]$ (already counted); the rest are new:

$$\text{contribution of } sa[i] = (n - sa[i]) - lcp[i] \quad (i \ge 1); \qquad \text{contribution of } sa[0] = n - sa[0]$$

**Why compare only with the adjacent predecessor?** In a sorted suffix array, the longest prefix $sa[i]$ shares with the set of suffixes before it equals exactly $lcp[i]$ — achieved with the adjacent predecessor $sa[i-1]$, while with farther suffixes the common prefix is no longer than $lcp[i]$. Thus every prefix of $sa[i]$ longer than $lcp[i]$ has never appeared before, and the first $lcp[i]$ prefixes were already counted — nothing is over- or under-counted.

**Corollary:** A substring occurring at several positions corresponds to a consecutive block of suffixes sharing that prefix. The first suffix of the block contributes the substring (its $lcp$ with the suffix just before the block is smaller than the substring's length), while the later ones have $lcp \ge$ the substring's length and subtract it — so the substring is counted exactly once.

### Step 3: Formula and algorithm

The total number of distinct substrings is:

$$\text{Result} = \sum_{i=0}^{n-1} (n - sa[i]) - \sum_{i=1}^{n-1} lcp[i]$$

The algorithm has three steps:

1. Build the suffix array $sa$ with the SA-IS algorithm.
2. Compute the LCP array with Kasai's algorithm.
3. Apply the formula above.

### Example

Using the example from the problem statement: $s = \text{"abaa"}$ ($n = 4$).

Suffix array (0-indexed) and LCP:

| $i$ | $sa[i]$ | suffix | $n - sa[i]$ | $lcp[i]$ | new contribution |
|---|---|---|---|---|---|
| 0 | 3 | a | 1 | — | 1 |
| 1 | 2 | aa | 2 | 1 | 1 |
| 2 | 0 | abaa | 4 | 1 | 3 |
| 3 | 1 | baa | 3 | 0 | 3 |

Explanation of contributions:

- $sa[0] = 3$ ($\text{"a"}$): no preceding suffix, all 1 prefix is new $\to \text{"a"}$.
- $sa[1] = 2$ ($\text{"aa"}$): $lcp[1] = 1$, the prefix $\text{"a"}$ already exists from $sa[0]$; 1 new prefix remains $\to \text{"aa"}$.
- $sa[2] = 0$ ($\text{"abaa"}$): $lcp[2] = 1$, the prefix $\text{"a"}$ already exists; 3 new prefixes remain $\to \text{"ab"}, \text{"aba"}, \text{"abaa"}$.
- $sa[3] = 1$ ($\text{"baa"}$): $lcp[3] = 0$, no overlap; all 3 prefixes are new $\to \text{"b"}, \text{"ba"}, \text{"baa"}$.

Total prefixes: $1 + 2 + 4 + 3 = 10$. Total LCP: $1 + 1 + 0 = 2$. Result: $10 - 2 = 8$.

The 8 distinct substrings: $\text{"a"}, \text{"b"}, \text{"aa"}, \text{"ab"}, \text{"ba"}, \text{"aba"}, \text{"baa"}, \text{"abaa"}$.

Result:
```
8
```

## Complexity

- **Time:** $O(n)$ $\textemdash$ building the suffix array with SA-IS and the LCP array with Kasai are both linear.
- **Memory:** $O(n)$ $\textemdash$ storing the suffix array, LCP array, and auxiliary arrays.

## Code (C++)

[Solution Code](../code/Distinct%20Substrings.cpp)
