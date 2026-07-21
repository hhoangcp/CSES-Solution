# Rectangle Cutting - Solution

**ID:** 1744 | **URL:** https://cses.fi/problemset/task/1744

## Approach

### Problem Restatement

Given an $a \times b$ rectangle ($1 \le a, b \le 500$), find the minimum number of cuts to divide it entirely into squares. Each cut splits one rectangle into two with integer side lengths.

### Core Idea

Let $dp[n][m]$ be the minimum number of **pieces** when dividing an $n \times m$ rectangle into squares. The answer is $dp[a][b] - 1$ (each cut adds exactly one piece).

If $n = m$, the rectangle is already a square: $dp[n][n] = 1$. Otherwise, we must make one first cut — either horizontal or vertical — and then optimally solve each half:

$$dp[n][m] = \min\left(\min_{i=1}^{n-1}\big(dp[i][m] + dp[n-i][m]\big),\min_{j=1}^{m-1}\big(dp[n][j] + dp[n][m-j]\big)\right)$$

**Correctness (optimal substructure):** Any cutting strategy starts with one first cut (horizontal at some $i$ or vertical at some $j$). After that cut, the two sub-rectangles must each be optimally divided — otherwise replacing a sub-optimal part with its optimum improves the total. By induction on area, $dp[n][m]$ correctly gives the minimum pieces.

### Algorithm

1. Base case: $dp[i][i] = 1$ for all $i$.
2. For each $(n, m)$ with $n \neq m$, try all horizontal cuts $i = 1 \ldots n-1$ and vertical cuts $j = 1 \ldots m-1$, take the minimum.
3. Output $dp[a][b] - 1$.

### Example

Input: $3 \times 5$. Key subproblems:

| Rectangle | Best cut | Pieces |
|-----------|----------|--------|
| $1 \times k$ | — | $k$ |
| $2 \times 2$ | — | 1 |
| $2 \times 3$ | vertical $j{=}1$ | $2{+}1 = 3$ |
| $2 \times 4$ | vertical $j{=}2$ | $1{+}1 = 2$ |
| $2 \times 5$ | vertical $j{=}1$ | $2{+}2 = 4$ |
| $3 \times 2$ | horizontal $i{=}1$ | $2{+}1 = 3$ |
| $3 \times 3$ | — | 1 |
| $3 \times 5$ | vertical $j{=}2$ | $3{+}1 = 4$ |

$dp[3][5] = 4$ pieces, answer $= 4 - 1 = \mathbf{3}$ cuts.

Cutting sequence: $3{\times}5 \xrightarrow{j=2}$ $3{\times}2 + 3{\times}3$; $3{\times}2 \xrightarrow{i=1}$ $1{\times}2 + 2{\times}2$; $1{\times}2 \xrightarrow{j=1}$ two $1{\times}1$.

## Complexity

- **Time:** $O(a^2 \cdot b + a \cdot b^2)$ — for each state $(n, m)$, iterate $O(n+m)$ cut positions
- **Space:** $O(a \cdot b)$

## Code (C++)

[Solution Code](../code/Rectangle%20Cutting.cpp)
