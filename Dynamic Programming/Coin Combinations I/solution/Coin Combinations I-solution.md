# Coin Combinations I - Solution

**ID:** 1635 | **URL:** https://cses.fi/problemset/task/1635

## Approach

### Problem Restatement

Given $n$ coin types and a target sum $x$, count the number of **ordered** ways to produce sum $x$ (different orderings of the same coins count as different ways).

### Core idea

The problem asks for **ordered** ways to produce sum $x$: sequences $(1,2)$ and $(2,1)$ count as different. Let $dp[i]$ be the number of ordered ways to produce sum $i$. Consider the **last** coin in the sequence: if it has value $c_j$ ($c_j \le i$), the preceding part produces sum $i - c_j$. Summing over all possible last coins:

$$dp[i] = \sum_{\substack{j=1 \\ c_j \le i}}^{n} dp[i - c_j]$$

The loop order is critical. We iterate $i$ from 1 to $x$ in the **outer** loop and $j$ from 1 to $n$ in the **inner** loop. This naturally distinguishes sequences by their last coin: two sequences with different last coins fall into different terms, and sequences with the same last coin but different orderings are already distinguished by induction on the prefix. This ensures no overcounting (disjoint terms) and no undercounting (every valid sequence has some last coin $c_j$, so it is counted via $dp[i - c_j]$). Contrast with Coin Combinations II, where swapping the loop order (coins outer, sum inner) counts **unordered** combinations.

### Algorithm

1. Initialize $dp[0] = 1$, $dp[1 \ldots x] = 0$.
2. For $i = 1$ to $x$:
   - For $j = 1$ to $n$:
     - If $c_j \le i$: $dp[i] = (dp[i] + dp[i - c_j]) \bmod (10^9 + 7)$.
3. Answer is $dp[x]$.

### Example

Input: $n = 3$, coins $= \{2, 3, 5\}$, $x = 9$.

| $i$ | $dp[i]$ | Computation |
|:---:|:---:|:---|
| 0 | 1 | Base |
| 1 | 0 | No coin $\le 1$ |
| 2 | 1 | $dp[0] = 1$ |
| 3 | 1 | $dp[1] + dp[0] = 0 + 1$ |
| 4 | 1 | $dp[2] + dp[1] = 1 + 0$ |
| 5 | 3 | $dp[3] + dp[2] + dp[0] = 1 + 1 + 1$ |
| 6 | 2 | $dp[4] + dp[3] + dp[1] = 1 + 1 + 0$ |
| 7 | 5 | $dp[5] + dp[4] + dp[2] = 3 + 1 + 1$ |
| 8 | 6 | $dp[6] + dp[5] + dp[3] = 2 + 3 + 1$ |
| 9 | 8 | $dp[7] + dp[6] + dp[4] = 5 + 2 + 1$ |

Result: $dp[9] = 8$ — the 8 ways are $2{+}2{+}5$, $2{+}5{+}2$, $5{+}2{+}2$, $3{+}3{+}3$, $2{+}2{+}2{+}3$, $2{+}2{+}3{+}2$, $2{+}3{+}2{+}2$, $3{+}2{+}2{+}2$.

## Complexity

- **Time:** $O(n \cdot x)$
- **Space:** $O(x)$

## Code (C++)

[Solution Code](../code/Coin%20Combinations%20I.cpp)
