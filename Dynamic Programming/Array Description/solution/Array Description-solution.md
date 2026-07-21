# Array Description - Solution

**ID:** 1746 | **URL:** https://cses.fi/problemset/task/1746

## Approach

### Problem Restatement

Given an array of $n$ values in $[1, m]$ where some positions are $0$ (unknown), count the number of ways to fill the unknowns so that adjacent elements differ by at most $1$.

### Core idea

The constraint $|a_i - a_{i+1}| \le 1$ means each element depends only on its immediate neighbor. This locality makes the problem a natural fit for DP over positions, where at each position we track the number of valid ways ending with each possible value.

Let $dp[i][v]$ be the number of valid ways to fill the first $i$ elements with $a_i = v$. The recurrence sums over the three possible previous values $\{v-1, v, v+1\} \cap [1, m]$:

$$dp[i][v] = \sum_{k=v-1}^{v+1} dp[i-1][k]$$

When $a_i$ is known (non-zero), only $dp[i][a_i]$ is updated; all other $dp[i][v]$ remain $0$, ensuring no array violates fixed values. This also guarantees no overcounting, since each valid array uniquely determines one path through the DP table (position $\times$ value).

### Algorithm

1. **Initialize** position 1:
   - If $a_1 = 0$: set $dp[1][v] = 1$ for all $v \in [1, m]$.
   - If $a_1 = v \neq 0$: set $dp[1][v] = 1$, all others $0$.
2. **Transition** for each position $i$ from $2$ to $n$:
   - If $a_i = 0$: for each $v \in [1, m]$, compute $dp[i][v] = \sum_{k=\max(1,v-1)}^{\min(m,v+1)} dp[i-1][k]$.
   - If $a_i = v \neq 0$: compute $dp[i][v] = \sum_{k=\max(1,v-1)}^{\min(m,v+1)} dp[i-1][k]$; set $dp[i][j] = 0$ for $j \neq v$.
3. **Answer**: $\sum_{v=1}^{m} dp[n][v] \pmod{10^9 + 7}$.

Use a rolling array of two rows (or overwrite in-place) since $dp[i]$ only depends on $dp[i-1]$.

### Example

Input: $n = 3$, $m = 5$, $a = [2, 0, 2]$.

**Position 1** ($a_1 = 2$): $dp[1] = [0, 1, 0, 0, 0]$ (values $1$ through $5$).

**Position 2** ($a_2 = 0$): Update all values:
- $dp[2][1] = dp[1][1] + dp[1][2] = 0 + 1 = 1$
- $dp[2][2] = dp[1][1] + dp[1][2] + dp[1][3] = 0 + 1 + 0 = 1$
- $dp[2][3] = dp[1][2] + dp[1][3] + dp[1][4] = 1 + 0 + 0 = 1$
- $dp[2][4] = dp[1][3] + dp[1][4] + dp[1][5] = 0 + 0 + 0 = 0$
- $dp[2][5] = dp[1][4] + dp[1][5] = 0 + 0 = 0$

**Position 3** ($a_3 = 2$): Only update $dp[3][2]$:
- $dp[3][2] = dp[2][1] + dp[2][2] + dp[2][3] = 1 + 1 + 1 = 3$

Result: $3$ — corresponding to arrays $[2,1,2]$, $[2,2,2]$, $[2,3,2]$.

## Complexity

- **Time:** $O(n \cdot m)$ — $n$ positions, each updating at most $m$ states (each state sums at most 3 values).
- **Space:** $O(m)$ — rolling array.

## Code (C++)

[Solution Code](../code/Array%20Description.cpp)
