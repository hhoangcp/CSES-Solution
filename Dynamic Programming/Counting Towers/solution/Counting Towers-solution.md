# Counting Towers - Solution

**ID:** 2413 | **URL:** https://cses.fi/problemset/task/2413

## Approach

### Problem Restatement

Count the number of ways to build a tower of width 2 and height $n$ using integer-sized blocks, such that every row is fully filled. There are $t$ queries. Output modulo $10^9 + 7$.

### Core idea

At each row, only two profiles matter: **split** (two separate columns) or **merged** (one block spanning width 2). The previous row's profile determines how the next row can be placed.

Let $dp[i][0]$ = ways to build height $i$ with the top row **split**, and $dp[i][1]$ = ways with top row **merged**.

**From split ($dp[i{-}1][0]$):** Each of the two columns can either extend upward or be capped with a new $1 \times 1$ block — 2 choices per column, giving $2 \times 2 = 4$ ways to stay split. Alternatively, place a $2 \times 1$ block across both columns — 1 way to become merged.

**From merged ($dp[i{-}1][1]$):** Place two separate $1 \times 1$ blocks on top — 1 way to become split. Or extend the merged block upward / cap it with a new $2 \times 1$ block — 2 ways to stay merged.

$$dp[i][0] = 4 \cdot dp[i-1][0] + dp[i-1][1]$$
$$dp[i][1] = dp[i-1][0] + 2 \cdot dp[i-1][1]$$

Each tower uniquely corresponds to a sequence of profiles $(s_1, \ldots, s_n)$ with $s_k \in \{\text{split}, \text{merged}\}$, and the construction bottom-up has exactly one transition per consecutive pair, so no overcounting. Every valid tower decomposes into a height $i{-}1$ tower plus the top row, so no undercounting.

### Algorithm

1. Initialize $dp[1][0] = dp[1][1] = 1$.
2. Precompute $dp[i][0]$ and $dp[i][1]$ for $i = 2$ to $10^6$ using the recurrence.
3. For each query $n$: output $(dp[n][0] + dp[n][1]) \bmod (10^9 + 7)$.

### Example

Input: $t = 3$, queries $n = 2, 6, 1337$.

| $i$ | $dp[i][0]$ | $dp[i][1]$ | Total |
|:---:|:---:|:---:|:---:|
| 1 | 1 | 1 | 2 |
| 2 | $4 \cdot 1 + 1 = 5$ | $1 + 2 \cdot 1 = 3$ | 8 |
| 3 | $4 \cdot 5 + 3 = 23$ | $5 + 2 \cdot 3 = 11$ | 34 |
| 4 | $4 \cdot 23 + 11 = 103$ | $23 + 2 \cdot 11 = 45$ | 148 |
| 5 | $4 \cdot 103 + 45 = 457$ | $103 + 2 \cdot 45 = 193$ | 650 |
| 6 | $4 \cdot 457 + 193 = 2021$ | $457 + 2 \cdot 193 = 843$ | 2864 |

- $n = 2$: total $= 8$.
- $n = 6$: total $= 2864$.
- $n = 1337$: total $= 640403945$.

## Complexity

- **Time:** $O(N_{\max} + t)$ — linear precomputation + $O(1)$ per query
- **Space:** $O(N_{\max})$

## Code (C++)

[Solution Code](../code/Counting%20Towers.cpp)
