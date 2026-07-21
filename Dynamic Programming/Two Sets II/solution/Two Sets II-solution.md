# Two Sets II - Solution

**ID:** 1093 | **URL:** https://cses.fi/problemset/task/1093

## Approach

### Problem Restatement

Count the number of ways to partition $\{1, 2, \ldots, n\}$ into two sets with equal sums. Output modulo $10^9 + 7$.

### Core Idea

The total sum is $S = n(n+1)/2$. If $S$ is odd, the answer is 0. Otherwise, the problem reduces to counting subsets with sum $S/2$ — each such subset $A$ pairs with its complement $B = \{1,\ldots,n\} \setminus A$ to form a valid partition.

**0/1 Knapsack DP:** Let $dp[j]$ be the number of subsets with sum $j$. Initialize $dp[0] = 1$. For each number $i$ from 1 to $n$, update $dp[j] = (dp[j] + dp[j-i]) \bmod (10^9+7)$ iterating $j$ from $S/2$ down to $i$ (reverse order ensures each $i$ is used at most once).

**Why divide by 2:** Each partition $\{A, B\}$ is counted twice — once for choosing $A$ and once for $B$. Since $S > 0$, no subset equals its complement, so the count is exactly doubled. The answer is $dp[S/2] \cdot 2^{-1} \bmod (10^9+7)$, where $2^{-1} \equiv 5 \times 10^8 + 4 \pmod{10^9+7}$.

**Correctness (invariant):** After processing numbers 1 through $i$, $dp[j]$ equals the number of subsets of $\{1, \ldots, i\}$ with sum $j$. Proof by induction: base case $i=0$ has only $dp[0]=1$ (empty set). When adding $i$, each new subset either excludes $i$ ($dp_{\text{old}}[j]$ ways) or includes $i$ (removing $i$ leaves a subset with sum $j-i$, counted by $dp_{\text{old}}[j-i]$). Reverse iteration preserves old values.

### Algorithm

1. If $S = n(n+1)/2$ is odd, output 0.
2. Initialize $dp[0] = 1$.
3. For $i = 1$ to $n$: for $j = S/2$ down to $i$: $dp[j] = (dp[j] + dp[j-i]) \bmod (10^9+7)$.
4. Output $dp[S/2] \cdot 2^{-1} \bmod (10^9+7)$.

### Example

$n = 7$, $S = 28$, $S/2 = 14$:

| After $i$ | $dp[14]$ |
|-----------|-----------|
| 1–4 | 0 |
| 5 | 1 |
| 6 | 4 |
| 7 | 8 |

$dp[14] = 8$, answer $= 8 \cdot 2^{-1} = \mathbf{4}$.

The 4 partitions: $\{1,3,4,6\}$/$\{2,5,7\}$, $\{1,2,5,6\}$/$\{3,4,7\}$, $\{1,2,4,7\}$/$\{3,5,6\}$, $\{1,6,7\}$/$\{2,3,4,5\}$.

## Complexity

- **Time:** $O(n \cdot S/2) = O(n^3)$ — with $S/2 \approx n^2/4$
- **Space:** $O(S) = O(n^2)$ — for the $dp$ array

## Code (C++)

[Solution Code](../code/Two%20Sets%20II.cpp)
