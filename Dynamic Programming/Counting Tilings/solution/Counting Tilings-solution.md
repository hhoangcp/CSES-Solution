# Counting Tilings - Solution

**ID:** 2181 | **URL:** https://cses.fi/problemset/task/2181

## Approach

### Problem Restatement

Count the number of ways to tile an $n \times m$ grid using $1 \times 2$ and $2 \times 1$ dominoes, modulo $10^9 + 7$.

### Core idea

Since $n \le 10$ is small, use **broken profile DP**: process cells left-to-right, top-to-bottom, tracking a bitmask of $n$ bits as the profile. Bit $k$ of the profile = 1 means cell in row $k+1$ of the current column is already occupied by a horizontal domino extending from the previous column.

For each cell $(i, j)$ and each profile $mask$, the transition handles three cases:

- **Cell occupied** (bit $i{-}1$ is 1): the cell is already filled by a horizontal domino from column $j{-}1$. Clear the bit: $mask' = mask \oplus (1 \ll (i{-}1))$.
- **Cell empty, place horizontal** (bit $i{-}1$ is 0): fill cells $(i, j)$ and $(i, j{+}1)$. Set the bit to mark the extension: $mask' = mask \oplus (1 \ll (i{-}1))$.
- **Cell empty, place vertical** (bit $i{-}1$ is 0, and $i > 1$ with bit $i{-}2$ also 0): fill cells $(i{-}1, j)$ and $(i, j)$. Mark cell $i{-}1$ as filled: $mask' = mask \oplus (1 \ll (i{-}2))$.

Notice the first two cases share the same XOR formula — placing a horizontal domino (setting a bit) and clearing a pre-filled cell both flip bit $i{-}1$, which is why the code handles them in one line. After processing all $n$ cells in column $j$, the profile encodes which horizontal dominoes extend to column $j{+}1$. We then reuse this profile as input for column $j{+}1$.

Each valid tiling corresponds to exactly one path through the DP: at each cell, the domino placement uniquely determines the next profile. Conversely, each path uniquely reconstructs a tiling. The answer is $dp[0]$ after all $n \times m$ cells — profile 0 means no domino extends outside the grid.

### Algorithm

1. Initialize $dp[0] = 1$, all other states $0$.
2. For each column $j = 1$ to $m$:
   - For each row $i = 1$ to $n$:
     - For each profile $mask$ from $0$ to $2^n - 1$:
       - $dp'[mask] = dp[mask \oplus (1 \ll (i{-}1))]$ (clear occupied / place horizontal).
       - If $i > 1$ and bits $i{-}1$ and $i{-}2$ of $mask$ are both 0: $dp'[mask] \mathrel{+}= dp[mask \oplus (1 \ll (i{-}2))]$ (place vertical).
     - Set $dp = dp'$.
3. Answer is $dp[0] \bmod (10^9 + 7)$.

### Example

Input: $n = 4$, $m = 7$. For illustration, trace $n = 2$, $m = 3$:

After processing each column, $dp[mask]$ values:

| After column | $dp[00]$ | $dp[01]$ | $dp[10]$ | $dp[11]$ |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 1 | 0 | 0 | 1 |
| 2 | 2 | 0 | 0 | 1 |
| 3 | 3 | 0 | 0 | — |

- **Column 1:** mask 00 = two vertical dominoes (1 way). mask 11 = two horizontal dominoes extending to column 2 (1 way).
- **Column 2:** From mask 00 → both vertical (→00) or both horizontal (→11). From mask 11 → both rows pre-filled, no choice (→00). So $dp[00]=1{+}1=2$, $dp[11]=1$.
- **Column 3:** Same transitions. $dp[00]=2{+}1=3$.

Result: $dp[0] = 3$. (The 3 tilings: all vertical; left two vertical + right horizontal pair; left horizontal pair + right two vertical.)

For the problem's input ($n=4, m=7$): $dp[0] = 781$.

## Complexity

- **Time:** $O(n \cdot m \cdot 2^n)$
- **Space:** $O(2^n)$

## Code (C++)

[Solution Code](../code/Counting%20Tilings.cpp)
