# Counting Sequences - Solution

**ID:** 2228 | **URL:** https://cses.fi/problemset/task/2228

## Approach

### Problem Restatement

Count the number of sequences of length $n$ where each element is in $\{1, \ldots, k\}$ and every number in $\{1, \ldots, k\}$ appears at least once. Result modulo $10^9 + 7$.

### Inclusion-Exclusion

Without the "at least once" constraint, the answer would simply be $k^n$. To enforce the constraint, let $A_j$ be the set of sequences where number $j$ does **not** appear. We need $|\overline{A_1} \cap \cdots \cap \overline{A_k}|$.

For a set $S \subseteq \{1, \ldots, k\}$, the number of sequences using only values in the complement $\bar{S}$ (of size $k - |S|$) is $(k - |S|)^n$. By inclusion-exclusion:

$$|\overline{A_1} \cap \cdots \cap \overline{A_k}| = \sum_{S \subseteq \{1,\ldots,k\}} (-1)^{|S|} (k-|S|)^n$$

Substituting $i = k - |S|$ (the number of allowed values) and noting there are $\binom{k}{k-i} = \binom{k}{i}$ sets $S$ with $|S| = k - i$:

$$\text{ans} = \sum_{i=0}^{k} (-1)^{k-i} \binom{k}{i} i^n$$

### Example

**Problem example:** $n = 6$, $k = 4$.

$$\sum_{i=0}^{4} (-1)^{4-i} \binom{4}{i} i^6 = 0 - 4 \cdot 1 + 6 \cdot 64 - 4 \cdot 729 + 1 \cdot 4096 = 0 - 4 + 384 - 2916 + 4096 = \mathbf{1560}$$

This matches the expected output. ✓

**Small example:** $n = 3$, $k = 2$.

$$\sum_{i=0}^{2} (-1)^{2-i} \binom{2}{i} i^3 = 0 - 2 \cdot 1 + 1 \cdot 8 = 6$$

The 6 valid sequences: $112, 121, 122, 211, 212, 221$.

## Complexity

- **Time:** $O(n + k \log n)$ — $O(n)$ for factorial preprocessing, $O(k \log n)$ for fast exponentiation in the summation loop.
- **Space:** $O(n)$ — for factorial and inverse factorial arrays.

## Code (C++)

[Solution Code](../code/Counting%20Sequences.cpp)
