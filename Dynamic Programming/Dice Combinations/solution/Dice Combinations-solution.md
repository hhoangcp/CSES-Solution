# Dice Combinations - Solution

**ID:** 1633 | **URL:** https://cses.fi/problemset/task/1633

## Approach

### Problem Restatement

Count the number of ordered ways to produce sum $n$ by rolling a 6-sided die one or more times. Each roll gives 1–6. Different orderings count as different ways. Output modulo $10^9 + 7$.

### Core idea

Let $dp[i]$ be the number of ordered ways to produce sum $i$. Consider the **last** roll: if it shows face $k$ ($1 \le k \le \min(6, i)$), the preceding rolls must produce sum $i - k$. Summing over all possible last rolls:

$$dp[i] = \sum_{k=1}^{\min(6,i)} dp[i - k]$$

No overcounting: two sequences from different $k$ values have different last rolls; sequences with the same last roll are already distinct by induction on the prefix. No undercounting: every valid sequence has some last roll $k$, so it is counted via $dp[i - k]$.

Base case: $dp[0] = 1$ (one way to produce sum 0: roll no dice).

### Algorithm

1. Initialize $dp[0] = 1$.
2. For $i = 1$ to $n$: $dp[i] = \sum_{k=1}^{\min(6,i)} dp[i - k] \bmod (10^9 + 7)$.
3. Answer is $dp[n]$.

### Example

Input: $n = 3$.

| $i$ | $dp[i]$ | Ways |
|:---:|:---:|:---|
| 0 | 1 | Base |
| 1 | $dp[0] = 1$ | $(1)$ |
| 2 | $dp[1] + dp[0] = 2$ | $(1,1), (2)$ |
| 3 | $dp[2] + dp[1] + dp[0] = 4$ | $(1,1,1), (1,2), (2,1), (3)$ |

Result: $dp[3] = 4$ — matching $1{+}1{+}1$, $1{+}2$, $2{+}1$, $3$.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Dice%20Combinations.cpp)
