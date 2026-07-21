# Dice Probability - Solution

**ID:** 1725 | **URL:** https://cses.fi/problemset/task/1725

## Approach

### Problem Restatement

Roll a die $n$ times ($1 \le n \le 100$), each giving 1–6 uniformly. Compute the probability the total falls in $[a, b]$, rounded to 6 decimal places (banker's rounding).

### Core Idea

Use DP on the sum distribution. Let $dp[i][j]$ be the probability of total $j$ after $i$ rolls. By the **law of total probability**, the last roll must be $k \in \{1, \ldots, 6\}$ and the previous total must be $j - k$:

$$dp[i][j] = \sum_{k=1}^{6} dp[i-1][j-k] \cdot \frac{1}{6}$$

Base: $dp[0][0] = 1$. After $i$ rolls, the sum lies in $[i, 6i]$, so only iterate $j$ in that range (treat $dp[i-1][j-k] = 0$ when $j - k < 0$).

The answer is the sum over disjoint events:

$$P(a \le S \le b) = \sum_{j=a}^{b} dp[n][j]$$

### Algorithm

1. Initialize $dp[0][0] = 1$.
2. For $i = 1$ to $n$: for $j = i$ to $6i$: $dp[i][j] = \frac{1}{6}\sum_{k=1}^{6} dp[i-1][j-k]$.
3. Sum $dp[n][j]$ for $j = a$ to $b$.

### Example

$n = 2$, $a = 9$, $b = 10$:

- $dp[1][j] = 1/6$ for $j = 1, \ldots, 6$.
- $dp[2][9] = \frac{1}{6}(0 + 0 + \frac{1}{6} + \frac{1}{6} + \frac{1}{6} + \frac{1}{6}) = \frac{4}{36}$
- $dp[2][10] = \frac{1}{6}(0 + 0 + 0 + \frac{1}{6} + \frac{1}{6} + \frac{1}{6}) = \frac{3}{36}$
- $P = \frac{4+3}{36} = \frac{7}{36} \approx 0.194444$

## Complexity

- **Time:** $O(n^2)$ — $n$ iterations, each processing up to $6n$ sums with 6 terms
- **Memory:** $O(n^2)$ — reducible to $O(n)$ with rolling array
