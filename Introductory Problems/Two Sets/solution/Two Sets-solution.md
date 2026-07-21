# Two Sets - Solution

**ID:** 1092 | **URL:** https://cses.fi/problemset/task/1092

## Approach

### Problem Restatement

Given $n$ ($1 \le n \le 10^6$), divide the numbers $1, 2, \ldots, n$ into two sets of equal sum. If impossible, print "NO".

### Core Idea

**Feasibility.** The total sum is $S = \frac{n(n+1)}{2}$. To split into two equal halves, $S$ must be even. Analyzing $n \bmod 4$:

| $n \bmod 4$ | $S$ parity | Feasible? |
|---|---|---|
| 0 | $S = 2k(4k+1)$, even | ✓ |
| 1 | $S = (4k+1)(2k+1)$, odd | ✗ |
| 2 | $S = (2k+1)(4k+3)$, odd | ✗ |
| 3 | $S = 2(4k+3)(k+1)$, even | ✓ |

A solution exists iff $n \bmod 4 \in \{0, 3\}$.

**Construction.** When feasible, find a subset summing to $\text{target} = S/2$ via a greedy prefix approach:

1. Accumulate $1 + 2 + \cdots + k$ until the sum $\ge \text{target}$. Let $k$ be the last number added.
2. Excess: $r = \frac{k(k+1)}{2} - \text{target}$.
3. **Set 1:** $\{1, \ldots, k\} \setminus \{r\}$ (remove $r$ if $r > 0$).
4. **Set 2:** $\{r\} \cup \{k+1, \ldots, n\}$ (include $r$ if $r > 0$).

**Correctness.** Since $k$ is the smallest integer with $\frac{k(k+1)}{2} \ge \text{target}$, we have $\frac{(k-1)k}{2} < \text{target}$, which gives $r < k$. This guarantees $r \in \{1, \ldots, k-1\}$, so removing $r$ from $\{1, \ldots, k\}$ is valid. Set 1 sums to $\frac{k(k+1)}{2} - r = \text{target}$; Set 2 sums to $r + S - \frac{k(k+1)}{2} = S - \text{target} = \text{target}$. The sets are disjoint (Set 1 uses $\{1, \ldots, k\} \setminus \{r\}$, Set 2 uses $\{r\} \cup \{k+1, \ldots, n\}$ with $r < k < k+1$) and cover all of $\{1, \ldots, n\}$.

### Algorithm

1. If $n \bmod 4 \in \{1, 2\}$, output "NO".
2. Otherwise, compute $\text{target} = \frac{n(n+1)}{4}$.
3. Find the smallest $k$ with $\frac{k(k+1)}{2} \ge \text{target}$. Compute $r = \frac{k(k+1)}{2} - \text{target}$.
4. Output Set 1 = $\{1, \ldots, k\} \setminus \{r\}$ and Set 2 = $\{r\} \cup \{k+1, \ldots, n\}$.

### Example

**Problem example 1 ($n = 7$):** $S = 28$, target = 14. $1+2+3+4+5 = 15 \ge 14$, so $k = 5$, $r = 1$.

- Set 1: $\{2, 3, 4, 5\}$ (sum 14)
- Set 2: $\{1, 6, 7\}$ (sum 14)

**Problem example 2 ($n = 6$):** $S = 21$, odd → "NO".

**Additional example ($n = 4$):** $S = 10$, target = 5. $1+2+3 = 6 \ge 5$, so $k = 3$, $r = 1$.

- Set 1: $\{2, 3\}$ (sum 5)
- Set 2: $\{1, 4\}$ (sum 5)

## Complexity

- **Time:** $O(n)$ — linear traversal to output the sets
- **Space:** $O(n)$ — to store the output sets

## Code (C++)

[Solution Code](../code/Two%20Sets.cpp)
