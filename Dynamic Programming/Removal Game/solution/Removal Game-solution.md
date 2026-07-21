# Removal Game - Solution

**ID:** 1097 | **URL:** https://cses.fi/problemset/task/1097

## Approach

### Problem Restatement

Given an array of $n$ integers, two players alternate removing one number from either end. Both play optimally to maximize their own score. Find the first player's maximum score.

### Core Idea

The game has a natural substructure: the subarray $[i, j]$. Let $dp[i][j]$ be the maximum score the **current player** can achieve from subarray $[i, j]$.

**Key insight:** The total score of both players on $[i, j]$ is fixed at $S(i,j) = \sum_{k=i}^{j} a_k$. If the current player takes $a_i$, the opponent gets $dp[i+1][j]$ on the remainder, so the current player gets $S(i,j) - dp[i+1][j]$. Similarly for $a_j$. Thus:

$$dp[i][j] = S(i,j) - \min\big(dp[i+1][j], dp[i][j-1]\big)$$

**Implementation form (alternating max/min):** Since $S(i,j)$ is constant, we can reformulate by tracking whose turn it is based on segment length parity relative to $n$:

- **First player's turn** (length has same parity as $n$): $dp[i][j] = \max(dp[i+1][j] + a_i, dp[i][j-1] + a_j)$
- **Second player's turn** (length has different parity): $dp[i][j] = \min(dp[i+1][j], dp[i][j-1])$

This directly computes the first player's score without tracking $S(i,j)$.

**Correctness:** By induction on segment length. When the first player chooses $a_i$, their total is $a_i + (S(i{+}1,j) - dp[i{+}1][j]) = S(i,j) - dp[i{+}1][j]$; the opponent's optimal play on $[i{+}1,j]$ is guaranteed by induction. Taking the max over both choices gives the optimum. The alternating min in the implementation captures the opponent minimizing the first player's remaining gain.

**Space optimization:** Since $dp[i][j]$ depends only on $dp[i+1][j]$ (previous row) and $dp[i][j-1]$ (same row), a 1D rolling array suffices: `pre[j]` stores the previous row before overwrite.

### Algorithm

1. Iterate $i$ from $n$ down to $1$.
2. For each $i$, iterate $j$ from $i$ to $n$.
3. Use parity of $(j - i + 1)$ vs $n$ to determine max or min.
4. Output $dp[n]$.

### Example

Array $[4, 5, 1, 3]$, $n = 4$ (even):

| $[i,j]$ | Length | Turn | $dp[i+1][j]$ | $dp[i][j-1]$ | $dp[i][j]$ |
|---------|--------|------|---------------|---------------|------------|
| $[4,4]$ | 1 | P2 | — | — | $0$ |
| $[3,3]$ | 1 | P2 | — | — | $0$ |
| $[3,4]$ | 2 | P1 | $0{+}3{=}3$ | $0{+}1{=}1$ | $3$ |
| $[2,2]$ | 1 | P2 | — | — | $0$ |
| $[2,3]$ | 2 | P1 | $0{+}1{=}1$ | $0{+}5{=}5$ | $5$ |
| $[2,4]$ | 3 | P2 | $5$ | $3$ | $3$ |
| $[1,1]$ | 1 | P2 | — | — | $0$ |
| $[1,2]$ | 2 | P1 | $0{+}5{=}5$ | $0{+}4{=}4$ | $5$ |
| $[1,3]$ | 3 | P2 | $5$ | $5$ | $5$ |
| $[1,4]$ | 4 | P1 | $5{+}3{=}8$ | $3{+}4{=}7$ | $\mathbf{8}$ |

Result: first player scores $\mathbf{8}$. Optimal play: P1 takes $a_4{=}3$, P2 takes $a_1{=}4$, P1 takes $a_2{=}5$, P2 takes $a_3{=}1$.

## Complexity

- **Time:** $O(n^2)$ — $O(n^2)$ states, each $O(1)$
- **Space:** $O(n)$ — 1D rolling array

## Code (C++)

[Solution Code](../code/Removal%20Game.cpp)
