# Longest Common Subsequence - Solution

**ID:** 3403 | **URL:** https://cses.fi/problemset/task/3403

## Approach

### Problem Restatement

Given two integer arrays $a_1, \ldots, a_n$ and $b_1, \ldots, b_m$, find their longest common subsequence (LCS). Print the length and one example subsequence.

### Core Idea

Let $dp[i][j]$ be the LCS length of prefixes $a[1..i]$ and $b[1..j]$. Consider the last element of each prefix:

- **If $a[i] = b[j]$:** We can match them as the last common element, then solve the remainder: $dp[i][j] = dp[i-1][j-1] + 1$.
- **If $a[i] \neq b[j]$:** At least one of $a[i]$, $b[j]$ is not in the LCS. Skip whichever gives the better result: $dp[i][j] = \max(dp[i-1][j],\ dp[i][j-1])$.

Base cases: $dp[0][j] = dp[i][0] = 0$.

**Why this is correct:** By induction on $i + j$. If $a[i] = b[j]$, any LCS either includes this pair (giving $dp[i-1][j-1] + 1$) or doesn't (but then we could include it for a longer result, contradiction). If $a[i] \neq b[j]$, any LCS excludes at least one of them, so its length is at most $\max(dp[i-1][j], dp[i][j-1])$; conversely, this maximum is achievable as a common subsequence of $a[1..i]$ and $b[1..j]$.

**Reconstruction:** Record transitions in a $trace[i][j]$ array during DP. Starting from $(n, m)$, if $a[i] = b[j]$, include $a[i]$ and move to $(i-1, j-1)$; otherwise move toward the direction with the larger $dp$ value. Reverse the collected elements.

### Example

Input: $a = [3, 1, 3, 2, 7, 4, 8, 2]$, $b = [6, 5, 1, 2, 3, 4]$.

DP table:

| | $\epsilon$ | 6 | 5 | 1 | 2 | 3 | 4 |
|--|-----------|---|---|---|---|---|---|
| $\epsilon$ | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 3 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| 1 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| 3 | 0 | 0 | 0 | 1 | 1 | 2 | 2 |
| 2 | 0 | 0 | 0 | 1 | 2 | 2 | 2 |
| 7 | 0 | 0 | 0 | 1 | 2 | 2 | 2 |
| 4 | 0 | 0 | 0 | 1 | 2 | 2 | 3 |
| 8 | 0 | 0 | 0 | 1 | 2 | 2 | 3 |
| 2 | 0 | 0 | 0 | 1 | 2 | 2 | 3 |

LCS length = 3. Traceback: $(8,6) \to \uparrow \to (7,6) \to \uparrow \to (6,6)$, $a[6]{=}b[6]{=}4$ → include 4; $(5,5) \to \leftarrow \to (5,4) \to \uparrow \to (4,4)$, $a[4]{=}b[4]{=}2$ → include 2; $(3,3) \to \uparrow \to (2,3)$, $a[2]{=}b[3]{=}1$ → include 1. Result: $[1, 2, 4]$.

## Complexity

- **Time:** $O(n \cdot m)$ — $n \cdot m$ states, each $O(1)$
- **Space:** $O(n \cdot m)$ — for $dp$ and $trace$ arrays

## Code (C++)

[Solution Code](../code/Longest%20Common%20Subsequence.cpp)
