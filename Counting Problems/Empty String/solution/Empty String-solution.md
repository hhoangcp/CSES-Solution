# Empty String - Solution

**ID:** 1080 | **URL:** https://cses.fi/problemset/task/1080

## Approach

### Problem Restatement

Given a string $s$ of length $n$, count the number of ways to completely delete it by repeatedly removing two adjacent equal characters. Result modulo $10^9 + 7$.

### Interval DP

Define $\text{dp}[i][j]$ = number of ways to completely delete substring $s[i \ldots j]$. A necessary condition is that $(j - i + 1)$ is even.

**Base case:** $\text{dp}[i][i-1] = 1$ (empty substring, one way — do nothing).

**Key observation:** The first character $s[i]$ must eventually pair with some matching $s[k]$ where $k > i$ and $s[i] = s[k]$. For this pair to become adjacent, all characters in $s[i{+}1 \ldots k{-}1]$ must be deleted first. After removing $s[i]$ and $s[k]$, the remaining substring $s[k{+}1 \ldots j]$ is deleted independently.

This gives two independent sub-processes:
1. **Delete $s[i{+}1 \ldots k{-}1]$, then pair $s[i]$ and $s[k]$:** takes $(k{-}i{+}1)/2$ steps.
2. **Delete $s[k{+}1 \ldots j]$:** takes $(j{-}k)/2$ steps.

These sub-processes are independent and their steps can be interleaved in any order (preserving internal ordering within each). Among the total $(j{-}i{+}1)/2$ steps, choose which $(k{-}i{+}1)/2$ belong to sub-process 1:

$$\text{dp}[i][j] = \sum_{\substack{k=i+1 \\ k \text{ step } 2}}^{j} [s[i] = s[k]] \cdot \text{dp}[i{+}1][k{-}1] \cdot \text{dp}[k{+}1][j] \cdot \binom{(j-i+1)/2}{(k-i+1)/2}$$

The step of 2 on $k$ ensures both sub-intervals have even length.

### Example

**Problem example:** $s = \texttt{aabccb}$ (1-indexed).

**Length 2:**
- $\text{dp}[1][2]$: "aa" — $k{=}2$, $s[1]{=}s[2]$. $1 \cdot 1 \cdot \binom{1}{1} = \mathbf{1}$.
- $\text{dp}[4][5]$: "cc" — $k{=}5$, $s[4]{=}s[5]$. $1 \cdot 1 \cdot \binom{1}{1} = \mathbf{1}$.
- $\text{dp}[2][3]$, $\text{dp}[3][4]$, $\text{dp}[5][6]$: no matching pair. $\mathbf{0}$.

**Length 4:**
- $\text{dp}[3][6]$: "bccb" — $k{=}6$, $s[3]{=}b{=}s[6]$. $\text{dp}[4][5] \cdot \text{dp}[7][6] \cdot \binom{2}{2} = 1 \cdot 1 \cdot 1 = \mathbf{1}$.
- $\text{dp}[1][4]$, $\text{dp}[2][5]$: no valid $k$. $\mathbf{0}$.

**Length 6:**
- $\text{dp}[1][6]$: "aabccb" — $k{=}2$, $s[1]{=}a{=}s[2]$. $\text{dp}[2][1] \cdot \text{dp}[3][6] \cdot \binom{3}{1} = 1 \cdot 1 \cdot 3 = \mathbf{3}$.

Result: **3**. ✓

The 3 deletion orders: (aa→cc→bb), (cc→aa→bb), (cc→bb→aa).

## Complexity

- **Time:** $O(n^3)$ — $O(n^2)$ intervals, each iterating $O(n)$ values of $k$.
- **Space:** $O(n^2)$ — for the DP table and precomputed binomial coefficients.

## Code (C++)

[Solution Code](../code/Empty%20String.cpp)
