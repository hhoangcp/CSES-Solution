# Grid Paths I - Solution

**ID:** 1638 | **URL:** https://cses.fi/problemset/task/1638

## Approach

### Problem Restatement

Given an $n \times n$ grid with traps (`*`) and empty cells (`.`), count the number of paths from $(1,1)$ to $(n,n)$ moving only right or down, avoiding trap cells. Output modulo $10^9 + 7$.

### Core idea

Let $dp[i][j]$ be the number of valid paths from $(1,1)$ to $(i,j)$. Since we can only move right or down, every path to $(i,j)$ must come from $(i{-}1,j)$ (down) or $(i,j{-}1)$ (right). These two categories are disjoint (different last move), so no overcounting. Every valid path must pass through one of these two predecessors at the penultimate step, so no undercounting.

$$dp[i][j] = \begin{cases} (dp[i-1][j] + dp[i][j-1]) \bmod (10^9+7) & \text{if cell } (i,j) \text{ is empty} \\ 0 & \text{if cell } (i,j) \text{ is a trap} \end{cases}$$

A trap cell contributes $0$ — no path can end there, and the $0$ propagates naturally to block paths that would need to pass through it.

Base case: $dp[1][1] = 1$ if empty, $0$ if trap. Boundary: $dp[i][0] = dp[0][j] = 0$.

### Algorithm

1. Initialize $dp[0][\cdot] = dp[\cdot][0] = 0$.
2. For $i = 1$ to $n$, for $j = 1$ to $n$:
   - If $(i,j)$ is a trap: $dp[i][j] = 0$.
   - If $(i,j) = (1,1)$ and empty: $dp[1][1] = 1$.
   - Otherwise: $dp[i][j] = (dp[i{-}1][j] + dp[i][j{-}1]) \bmod (10^9 + 7)$.
3. Output $dp[n][n]$.

### Example

Input: $n = 4$, grid (traps at $(2,2)$, $(3,4)$, $(4,1)$):

```
. . . .
. * . .
. . . *
* . . .
```

| | $j{=}1$ | $j{=}2$ | $j{=}3$ | $j{=}4$ |
|:---:|:---:|:---:|:---:|:---:|
| $i{=}1$ | 1 | 1 | 1 | 1 |
| $i{=}2$ | 1 | 0 | 1 | 2 |
| $i{=}3$ | 1 | 1 | 2 | 0 |
| $i{=}4$ | 0 | 1 | 3 | 3 |

Key observations: $dp[2][2]=0$ (trap), blocking row 2 from the left. $dp[3][4]=0$ (trap), forcing all paths through row 4 to come from $(4,3)$. $dp[4][1]=0$ (trap), but $(4,2)$ still reachable from $(3,2)$.

Result: $dp[4][4] = 3$.

## Complexity

- **Time:** $O(n^2)$
- **Space:** $O(n^2)$ (optimizable to $O(n)$ with rolling row)

## Code (C++)

[Solution Code](../code/Grid%20Paths%20I.cpp)
