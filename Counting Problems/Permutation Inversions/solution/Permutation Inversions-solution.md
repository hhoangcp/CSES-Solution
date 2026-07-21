# Permutation Inversions - Solution

**ID:** 2229 | **URL:** https://cses.fi/problemset/task/2229

## Approach

### Problem Restatement

Count the number of permutations of $\{1, \ldots, n\}$ with exactly $k$ inversions. Result modulo $10^9 + 7$.

### Generating function

Build permutations by inserting elements $1, 2, \ldots, n$ one at a time. When inserting element $i$ into a permutation of $\{1, \ldots, i-1\}$, there are $i$ possible positions. Inserting at position $t$ from the right (counting from 0) creates exactly $t$ new inversions. The factor for element $i$ is:

$$\sum_{t=0}^{i-1} x^t = \frac{1 - x^i}{1 - x}$$

The generating function for the total number of inversions is:

$$I_n(x) = \prod_{i=1}^{n} \frac{1 - x^i}{1 - x} = \frac{P(x)}{(1-x)^n} \quad \text{where } P(x) = \prod_{i=1}^{n}(1-x^i)$$

### Separating numerator and denominator

**Denominator:** $(1-x)^{-n} = \sum_{j \ge 0} \binom{n-1+j}{n-1} x^j$ (generalized binomial series).

**Numerator:** $P(x) = \prod_{i=1}^{n}(1-x^i)$. Each subset $S \subseteq \{1, \ldots, n\}$ contributes $(-1)^{|S|} x^{\sum S}$. So the coefficient $P_j$ counts (with alternating signs) subsets of $\{1, \ldots, n\}$ summing to $j$.

**Combining:** $[x^k] I_n(x) = \sum_{i=0}^{k} P_i \cdot \binom{n-1+k-i}{n-1}$.

### Computing numerator coefficients via partition DP

$P_j = \sum_{m=0}^{\sqrt{2k}} (-1)^m \cdot dp[m][j]$, where $dp[m][j]$ = number of $m$-element subsets of $\{1, \ldots, n\}$ summing to $j$. The bound $m \le \sqrt{2k}$ follows because $1 + 2 + \cdots + m = m(m+1)/2 \le k$.

The DP transition exploits the "shift and add" structure of distinct partitions:

$$dp[m][j] = dp[m][j-m] + dp[m-1][j-m]$$

- **$dp[m][j-m]$:** Take a partition of $m$ distinct parts summing to $j-m$, increment each part by 1 (total increase $m$).
- **$dp[m-1][j-m]$:** Take a partition of $m-1$ distinct parts summing to $j-m$, increment each by 1, and add a new part of value 1 (total increase $m-1+1 = m$).

**Upper bound $n$:** After incrementing, if a part reaches $n+1$, it violates the constraint. Subtract $dp[m-1][j-(n+1)]$ to remove these cases (the part that exceeded $n$ is "absorbed" back, reducing the count by 1).

### Symmetry optimization

$I_n(k) = I_n\left(\binom{n}{2} - k\right)$: replacing each element $\pi(i)$ with $n+1-\pi(i)$ reverses all relative orders, converting $k$ inversions to $\binom{n}{2} - k$. So replace $k$ with $\min\left(k, \binom{n}{2} - k\right)$ to reduce computation.

### Example

**Problem example:** $n = 4$, $k = 3$.

Subsets of $\{1,2,3,4\}$ and their contributions to $P(x)$:

| Sum $j$ | Subsets | $P_j$ |
|---------|---------|-------|
| 0 | $\emptyset$ | $+1$ |
| 1 | $\{1\}$ | $-1$ |
| 2 | $\{2\}$ | $-1$ |
| 3 | $\{3\},\{1,2\}$ | $-1+1=0$ |

$$\text{ans} = 1 \cdot \binom{6}{3} + (-1) \cdot \binom{5}{3} + (-1) \cdot \binom{4}{3} + 0 \cdot \binom{3}{3} = 20 - 10 - 4 = \mathbf{6}$$

The 6 permutations: $[1,4,3,2]$, $[2,3,4,1]$, $[2,4,1,3]$, $[3,1,4,2]$, $[3,2,1,4]$, $[4,1,2,3]$. ✓

## Complexity

- **Time:** $O(k\sqrt{k})$ — partition DP has $O(\sqrt{k})$ levels, each processing $O(k)$ entries.
- **Space:** $O(k)$ — rolling array over DP rows.

## Code (C++)

[Solution Code](../code/Permutation%20Inversions.cpp)
