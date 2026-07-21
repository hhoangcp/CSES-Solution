# Coin Combinations II - Solution

**ID:** 1636 | **URL:** https://cses.fi/problemset/task/1636

## Approach

### Problem Restatement

Given $n$ coin types and a target sum $x$, count the number of **unordered** ways to produce sum $x$ (different orderings of the same multiset count as one).

### Core idea

This is the **unordered** variant of Coin Combinations I: two different orderings of the same multiset count as one. The key is the loop order — iterating **coins in the outer loop** and **sum in the inner loop** enforces a canonical ordering on the coins.

Let $dp[i]$ be the number of unordered ways to produce sum $i$ using coins processed so far. After processing coins $c_1, \ldots, c_j$, $dp[i]$ counts ways using only those coins. When adding coin $c_{j+1}$ (iterating $i$ from $c_{j+1}$ to $x$ forward), we extend each existing multiset by $0, 1, 2, \ldots$ copies of $c_{j+1}$. This works because the forward iteration on $i$ allows $c_{j+1}$ to be used multiple times within the same round.

No overcounting: each multiset has a unique count vector $(a_1, \ldots, a_n)$. Coin $c_j$ is only introduced at step $j$, so the multiset is built in exactly one way — adding $a_j$ copies of $c_j$ at step $j$. No undercounting: every valid multiset producing sum $x$ will be built when the last coin type it uses is processed.

Contrast with Coin Combinations I (sum outer, coins inner): there, each position in the sequence freely chooses any coin, so different orderings are counted separately.

### Algorithm

1. Initialize $dp[0] = 1$, $dp[1 \ldots x] = 0$.
2. For $j = 1$ to $n$:
   - For $i = c_j$ to $x$: $dp[i] = (dp[i] + dp[i - c_j]) \bmod (10^9 + 7)$.
3. Answer is $dp[x]$.

### Example

Input: $n = 3$, coins $= \{2, 3, 5\}$, $x = 9$.

**After $c_1 = 2$:** $dp = [1, 0, 1, 0, 1, 0, 1, 0, 1, 0]$

| $i$ | $dp[i]$ | Ways |
|:---:|:---:|:---|
| 2 | 1 | $\{2\}$ |
| 4 | 1 | $\{2,2\}$ |
| 6 | 1 | $\{2,2,2\}$ |
| 8 | 1 | $\{2,2,2,2\}$ |

**After $c_2 = 3$:** $dp = [1, 0, 1, 1, 1, 1, 2, 1, 2, 2]$

| $i$ | $dp[i]$ | New ways added |
|:---:|:---:|:---|
| 5 | 1 | $\{2,3\}$ |
| 9 | 2 | $\{2,2,2,3\}$, $\{3,3,3\}$ |

**After $c_3 = 5$:** $dp = [1, 0, 1, 1, 1, 2, 2, 2, 3, 3]$

| $i$ | $dp[i]$ | New ways added |
|:---:|:---:|:---|
| 9 | 3 | $\{2,2,5\}$ |

Result: $dp[9] = 3$ — the 3 ways are $\{2,2,5\}$, $\{3,3,3\}$, $\{2,2,2,3\}$.

Compared to Coin Combinations I with the same input giving 8 ordered ways, the 8 sequences collapse into 3 multisets.

## Complexity

- **Time:** $O(n \cdot x)$
- **Space:** $O(x)$

## Code (C++)

[Solution Code](../code/Coin%20Combinations%20II.cpp)
