# Edit Distance - Solution

**ID:** 1639 | **URL:** https://cses.fi/problemset/task/1639

## Approach

### Problem Restatement

Given two strings $S$ and $T$ of lengths $n$ and $m$, find the minimum number of operations (insert, delete, replace a character) to transform $S$ into $T$.

### Core idea

Let $dp[i][j]$ be the edit distance between prefixes $S[1..i]$ and $T[1..j]$. Consider the last operation affecting position $i$ of $S$ or position $j$ of $T$:

- **Match/Replace** at $(i, j)$: cost $0$ if $S[i] = T[j]$, else $1$. Preceding operations transform $S[1..i{-}1]$ into $T[1..j{-}1]$: $dp[i{-}1][j{-}1] + [S[i] \neq T[j]]$.
- **Delete** $S[i]$: cost $1$. Preceding operations transform $S[1..i{-}1]$ into $T[1..j]$: $dp[i{-}1][j] + 1$.
- **Insert** $T[j]$: cost $1$. Preceding operations transform $S[1..i]$ into $T[1..j{-}1]$: $dp[i][j{-}1] + 1$.

$$dp[i][j] = \min(dp[i{-}1][j{-}1] + [S[i] \neq T[j]], dp[i{-}1][j] + 1, dp[i][j{-}1] + 1)$$

Any optimal sequence must end with one of these three operation types, so the minimum over all three is correct — no undercounting. Each operation type leads to a strictly smaller subproblem ($i{+}j$ decreases or $i$ or $j$ decreases), so induction applies — no overcounting.

Base cases: $dp[0][j] = j$ (insert $j$ characters) and $dp[i][0] = i$ (delete $i$ characters).

### Algorithm

1. Initialize $dp[0][j] = j$ for $j = 0 \ldots m$.
2. For $i = 1$ to $n$:
   - Set $dp[i][0] = i$.
   - For $j = 1$ to $m$: $dp[i][j] = \min(dp[i{-}1][j{-}1] + [S[i] \neq T[j]], dp[i{-}1][j] + 1, dp[i][j{-}1] + 1)$.
3. Answer is $dp[n][m]$.

Use a rolling two-row array since each row depends only on the previous row.

### Example

Input: $S = \text{LOVE}$, $T = \text{MOVIE}$.

| | | M | O | V | I | E |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| | 0 | 1 | 2 | 3 | 4 | 5 |
| **L** | 1 | 1 | 2 | 3 | 4 | 5 |
| **O** | 2 | 2 | 1 | 2 | 3 | 4 |
| **V** | 3 | 3 | 2 | 1 | 2 | 3 |
| **E** | 4 | 4 | 3 | 2 | 2 | 2 |

Result: $dp[4][5] = 2$ — replace L→M, insert I.

## Complexity

- **Time:** $O(n \cdot m)$
- **Space:** $O(m)$

## Code (C++)

[Solution Code](../code/Edit%20Distance.cpp)
